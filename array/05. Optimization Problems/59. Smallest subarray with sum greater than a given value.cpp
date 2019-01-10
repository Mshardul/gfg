#include <iostream>
using namespace std;

/*
// T(n): O(n^2); S(n): O(n);
int main(int argc, char const *argv[])
{
	int n, k, ans;
	cin>>n;
	int a[n];
	for(int i=0; i<n; i++)
		cin>>a[i];
	cin>>k;
	int found=0;
	for(int i=1; i<n; i++){
		a[i]+=a[i-1];
		if(found==0 && a[i]>k){
			ans=i+1;
			found=1;
		}
	}
	if(found==0)
		ans=n;
	for(int i=0; i<n; i++){
		for(int j=i; j<n; j++){
			if(a[j]-a[i]>k){
				ans=min(ans, j-i);
				// cout<<i+1<<" "<<j<<" "<<ans<<endl;
				break;
			}
		}
	}
	cout<<ans<<endl;
	return 0;
}
*/

// T(n): O(n); S(n): O(1);
int main(int argc, char const *argv[])
{
	int n, k;
	cin>>n;
	int a[n];
	for(int i=0; i<n; i++)
		cin>>a[i];
	cin>>k;
	int l=0, r=0, curr_sum=0, ind=n+1;
	while(1){
		while(r<n){
			curr_sum+=a[r++];
			if(curr_sum>k)
				break;
		}
		ind=min(ind, r-l+1);
		while(curr_sum>k)
			curr_sum-=a[l++];
		ind=min(ind, r-l+2);
		cout<<l<<" "<<r<<endl;
	}
	return 0;
}