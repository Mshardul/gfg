#include <iostream>
using namespace std;

// T(n): O(n log n); S(n): O(1);
int main(int argc, char const *argv[])
{
	int n, k;
	cin>>n;
	cin>>k;
	int a[n];
	for(int i=0; i<n; i++)
		cin>>a[i];
	sort(a, a+n);
	int ind=-1, diff=INT_MAX;
	for(int i=0; i<n; i++){
		if(max(a[i]-k, k-a[i])<diff){
			ind=i;
			diff=max(a[i]-k, k-a[i]);
		}
	}
	cout<<a[ind]<<" ";
	int l=ind-1;
	int r=ind+1;
	while(l>-1&&r<n){
		int left = max(a[l]-k, k-a[l]);
		int right = max(a[r]-k, k-a[r]);
		if(left>right)
			cout<<a[r++]<<" ";
		else
			cout<<a[l--]<<" ";
	}
	while(l>-1)
		cout<<a[l--]<<" ";
	while(r<n)
		cout<<a[r++]<<" ";
	cout<<endl;
	return 0;
}