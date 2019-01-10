#include <iostream>
using namespace std;

// T(n): O(n); S(n): O(1);
int main(int argc, char const *argv[])
{
	int n, a[1000], si=0, k;
	cin>>n;
	for(int i=0; i<n; i++)
		cin>>a[i];
	cin>>k;
	k = k%n;
	for(int i=0; i<n; i++)
		cout<<a[(k+i)%n];
	return 0;
}