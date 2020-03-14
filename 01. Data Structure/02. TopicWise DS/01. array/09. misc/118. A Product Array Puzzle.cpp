#include <iostream>
using namespace std;

/*
// T(n): O(n); S(n): O(2n);
int main(int argc, char const *argv[])
{
	int n;
	cin>>n;
	int a[n];
	for(int i=0; i<n; i++)
		cin>>a[i];
	int l[n], r[n];

	l[0]=1;
	for(int i=1; i<n; i++){
		l[i]=l[i-1]*a[i-1];
	}

	r[n-1]=1;
	for(int i=n-2; i>-1; i--)
		r[i]=r[i+1]*a[i+1];

	for(int i=0; i<n; i++)
		cout<<l[i]*r[i]<<" ";
	cout<<endl;

	return 0;
}
*/

// T(n): O(n); S(n): O(n);
int main(int argc, char const *argv[])
{
	int n;
	cin>>n;
	int a[n];
	for(int i=0; i<n; i++)
		cin>>a[i];

	int res[n];

	int mult=1;
	for(int i=0; i<n; i++){
		res[i]=mult;
		mult*=a[i];
	}

	mult=1;
	for(int i=n-1; i>-1; i--){
		res[i]*=mult;
		mult*=a[i];
	}

	for(int i=0; i<n; i++)
		cout<<res[i]<<" ";
	cout<<endl;
	return 0;
}