#include <iostream>
using namespace std;

/*
// T(n): O(n); S(n): O(n) //not inorder
int main(int argc, char const *argv[])
{
	int n, a[100], b[100];
	cin>>n;
	for(int i=0; i<n; i++)
		cin>>a[i];
	int l=0, r=n-1;
	for(int i=0; i<n; i++){
		if(a[i]>0)
			b[l++]=a[i];
		else
			b[r--]=a[i];
	}
	for(int i=0; i<n; i++)
		cout<<b[i]<<" ";
	return 0;
}
*/

/*
// T(n): O(n); S(n): O(n); //inorder
int main(int argc, char const *argv[])
{
	int n, a[100], b[100];
	cin>>n;
	for(int i=0; i<n; i++)
		cin>>a[i];
	int c=0;
	for(int i=0; i<n; i++){
		if(a[i]>0)
			c++;
	}
	int l=0;
	for(int i=0; i<n; i++){
		if(a[i]>0)
			b[l++]=a[i];
		else
			b[c++]=a[i];
	}
	for(int i=0; i<n; i++)
		cout<<b[i]<<" ";
	return 0;
}
*/

