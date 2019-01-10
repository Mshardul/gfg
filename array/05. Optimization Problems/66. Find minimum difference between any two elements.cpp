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
	int min_diff=INT_MAX;
	for(int i=1; i<n; i++)
		min_diff=min(min_diff, a[i]-a[i-1]);
	cout<<min_diff<<endl;
	return 0;
}