#include <iostream>
using namespace std;

int main(int argc, char const *argv[])
{
	int n, a[1000], temp;
	cin>>n;
	for (int i=0; i<n; ++i)
		cin>>a[i];
	for(int i=0; i<n/2; i++){
		temp=a[i];
		a[i]=a[n-1-i];
		a[n-1-i]=temp;
	}
	for (int i=0; i<n; ++i)
		cout<<a[i]<<" ";

	return 0;
}