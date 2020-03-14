#include <iostream>
using namespace std;

/*
// T(n): O(n); S(n): O(1);
int main(int argc, char const *argv[])
{
	int n, a[100], max;
	cin>>n;
	for(int i=0; i<n; i++)
		cin>>a[i];
	max=a[0];
	for(int i=1; i<n; i++)
		if(max<a[i])
			max=a[i];
	cout<<max;
	return 0;
}
*/

//using inbuilt stl function
int main(int argc, char const *argv[])
{
	int n, a[100];
	cin>>n;
	for(int i=0; i<n; i++)
		cin>>a[i];
	cout<<*max_element(a, a+n);
	return 0;
}