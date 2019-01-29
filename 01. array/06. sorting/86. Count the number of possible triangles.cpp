#include <iostream>
using namespace std;

// T(n): O(n^2); S(n): O(1);
int main(int argc, char const *argv[])
{
	int n, ans=0;
	cin>>n;
	int a[n];
	for(int i=0; i<n; i++)
		cin>>a[i];
	sort(a, a+n);
	for(int i=0; i<n; i++){
		int k=i+2;
		for(int j=i+1; j<n; j++){
			while(k<n && a[k]>a[i]+a[j])
				k++;
			if(k>j)
				ans+=k-j-1;
		}
	}
	cout<<ans<<endl;
	return 0;
}