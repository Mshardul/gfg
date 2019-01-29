#include <iostream>
using namespace std;

//MOs algo is not used here. this one is efficient.
//T(n): O(n);
int main(int argc, char const *argv[])
{
	int n, q;
	cin>>n;
	int a[n];
	for(int i=0; i<n; i++)
		cin>>a[i];
	for(int i=1; i<n; i++)
		a[i]+=a[i-1];
	cin>>q;
	while(q-->0){
		int l, r;
		cin>>l;
		cin>>r;
		if(l==0)
			cout<<a[r]<<endl;
		else
			cout<<a[r]-a[l-1]<<endl;
	}
	return 0;
}