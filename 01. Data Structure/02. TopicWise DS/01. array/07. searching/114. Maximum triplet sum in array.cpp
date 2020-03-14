#include <iostream>
using namespace std;

/*
//T(n): O(n log n);
int main(int argc, char const *argv[])
{
	int n;
	cin>>n;
	int a[n];
	for(int i=0; i<n; i++)
		cin>>a[i];
	sort(a, a+n);
	cout<<a[n-1]+a[n-2]+a[n-3];
	return 0;
}
*/

//assuming array elements to be distinct
//T(n): O(n); S(n): O(1);
int main(int argc, char const *argv[])
{
	int n;
	cin>>n;
	int a[n];
	for(int i=0; i<n; i++)
		cin>>a[i];
	int x=INT_MIN, y=INT_MIN, z=INT_MIN;
	for(int i=0; i<n; i++){
		if(a[i]>x){
			z=y;
			y=x;
			x=a[i];
		}
		else if(a[i]>y){
			z=y;
			y=a[i];
		}
		else if(a[i]>z)
			z=a[i];
	}
	cout<<x<<" "<<y<<" "<<z<<endl;
	return 0;
}