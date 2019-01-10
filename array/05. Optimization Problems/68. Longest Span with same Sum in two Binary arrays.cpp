#include <iostream>
using namespace std;

// T(n): O(n^2); S(n): O(1);
int main(int argc, char const *argv[])
{
	int n;
	cin>>n;
	int a[n+1], b[n+1];
	a[0]=0;
	b[0]=0;
	for(int i=1; i<=n; i++)
		cin>>a[i];
	for(int i=1; i<=n; i++)
		cin>>b[i];

	for(int i=2; i<=n; i++){
		a[i]+=a[i-1];
		b[i]+=b[i-1];
	}

	for(int i=0; i<=n; i++)
		cout<<a[i]<<" ";
	cout<<endl;
	for(int i=0; i<=n; i++)
		cout<<b[i]<<" ";
	cout<<endl;

	
	return 0;
}