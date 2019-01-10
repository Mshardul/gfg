#include <iostream>
using namespace std;

//something is wrong; approach is correct; do check;
// T(n): O(n); S(n): O(1);
int main(int argc, char const *argv[])
{
	int n;
	cin>>n;
	int a[n];
	for(int i=0; i<n; i++)
		cin>>a[i];
	int l=0, r=n-1, orig_l=-1, orig_r=n;
	int sum_l=0, sum_r=0;
	int ans=0;
	while(l<=r){
		if(sum_l==sum_r){
			if(orig_l==l)
				ans++;
			if(orig_r==r)
				ans++;
			orig_l=l;
			orig_r=r;
			sum_l=a[l++];
			sum_r=a[r--];
		}
		else if(sum_l<sum_r){
			sum_l+=a[l++];
		}
		else{
			sum_r+=a[r--];
		}
	}
	cout<<ans;
	return 0;
}