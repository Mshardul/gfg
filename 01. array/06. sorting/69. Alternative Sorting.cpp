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
	while(l<r)
		cout<<a[r--]<<" "<<a[l++]<<" ";
	if(l==r)
		cout<<a[r];
	cout<<endl;
	return 0;
}