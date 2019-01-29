#include <iostream>
using namespace std;

// T(n): O(n); S(n): O(1);
int main(int argc, char const *argv[])
{
	int n;
	cin>>n;
	int a[n];
	for(int i=0; i<n; i++)
		cin>>a[i];
	int sum=1;
	for(int i=0; i<n; i++){
		if(a[i]>sum)
			break;
		sum+=a[i];
	}
	cout<<sum<<endl;
}