#include <iostream>
using namespace std;

// T(n): O(n log n); S(n): O(1);
int main(int argc, char const *argv[])
{
	int n, k, ans=0;
	cin>>n;
	cin>>k;
	int a[n];
	for(int i=0; i<n; i++)
		cin>>a[i];
	sort(a, a+n);
	int l=0, r=1;
	while(l<n && r<n){
		if(a[r]-a[l]==k){
			ans++;
			cout<<l<<" "<<r<<endl;
			l++;
		}
		else
			r++;
	}
	cout<<ans<<endl;
	return 0;
}