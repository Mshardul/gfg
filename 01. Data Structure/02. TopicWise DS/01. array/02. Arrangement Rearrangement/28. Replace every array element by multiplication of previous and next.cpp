#include <iostream>
using namespace std;

// T(n): O(n); S(n): O(1);
int main(int argc, char const *argv[])
{
	int n, a[100];
	cin>>n;
	for(int i=0; i<n; i++)
		cin>>a[i];
	int old=a[0];
	a[0]=a[0]*a[1];
	for(int i=1; i<n-1; i++){
		int temp=a[i];
		a[i]=old*a[i+1];
		old=temp;
	}
	a[n-1]=old*a[n-1];
	for(int i=0; i<n; i++)
		cout<<a[i]<<" ";
	return 0;
}