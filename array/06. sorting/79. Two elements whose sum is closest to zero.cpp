#include <iostream>
using namespace std;

// T(n): O(n log n); S(n): O(1);
int main(int argc, char const *argv[])
{
	int n;
	cin>>n;
	int a[n];
	for(int i=0; i<n; i++)
		cin>>a[i];
	sort(a, a+n);
	int l=0, r=n-1;
	int ans=INT_MAX;
	while(l<r){
		int diff=a[r]+a[l];
		int abs_diff=diff;
		if(diff<0){
			l++;
			abs_diff=diff*-1;
		}
		else{
			r--;
		}
		if(abs_diff<ans)
			ans=diff;
	}
	cout<<ans<<endl;
	return 0;
}