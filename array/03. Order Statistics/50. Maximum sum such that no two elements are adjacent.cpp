#include <iostream>
using namespace std;

//considering only positive elements here
// T(n): O(n); S(n): O(1);
int main(int argc, char const *argv[])
{
	int n;
	cin>>n;
	int a[n];
	for(int i=0; i<n; i++)
		cin>>a[i];
	a[2]+=a[0];
	for(int i=3; i<n; i++)
		a[i]+=max(a[i-2], a[i-3]);
	cout<<max(a[n-1], a[n-2]);
	return 0;
}