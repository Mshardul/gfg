#include <iostream>
using namespace std;


//using modified kadane's algo
//T(n): O((m+n) log m); S(n): O(1);
bool Exists(int b[], int l, int r, int ele){
	if(ele<b[l])
		return false;
	if(ele>b[r])
		return false;
	int mid=(l+r)/2;
	if(ele==mid)
		return true;
	if(ele<mid)
		return Exists(b, l, mid-1, ele);
	return Exists(b, mid+1, r, ele);
}

int main(int argc, char const *argv[])
{
	int n, m;
	cin>>n;
	cin>>m;
	int a[n], b[m];
	for(int i=0; i<n; i++)
		cin>>a[i];
	for(int i=0; i<m; i++)
		cin>>b[i];
	int sum=0, max=INT_MIN;
	sort(b, b+m);
	for(int i=0; i<n; i++){
		if(Exists(b, 0, m-1, a[i]) || sum<0){
			if(sum>max)
				max=sum;
			sum=0;
		}
		else
			sum+=a[i];
	}
	if(max<sum)
		max=sum;
	cout<<max<<endl;
	return 0;
}
