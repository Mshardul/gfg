#include <iostream>
using namespace std;

int main(int argc, char const *argv[])
{
	int n, k;
	cin>>n;
	cin>>k;
	int a[n];
	for(int i=0; i<n; i++)
		cin>>a[i];

	// sort(a, a+n);
	int l=0, r=1, mult=a[0], ans=0;

	while(r<n && l<=r){
		if(mult<k){
			mult*=a[r++];
		}
		else{
			if(mult==k){
				ans++;
			}
			mult/=a[l++];
		}
	}
	cout<<ans<<endl;
	return 0;
}