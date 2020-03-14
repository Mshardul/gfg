#include <iostream>
using namespace std;

/*
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
		cout<<a[l];
	cout<<endl;
	return 0;
}
*/

// T(n): O(n); S(n): O(1);
int main(int argc, char const *argv[])
{
	int n;
	cin>>n;
	int a[n];
	for(int i=0; i<n; i++)
		cin>>a[i];
	if(a[0]<a[1])
		swap(a[0], a[1]);
	for(int i=2; i<n; i+=2){
		if(a[i]<a[i-1])
			swap(a[i], a[i-1]);
		if(a[i]<a[i+1])
			swap(a[i], a[i+1]);
	}
	for(int i=0; i<n; i++)
		cout<<a[i]<<" ";
	cout<<endl;
	return 0;
}