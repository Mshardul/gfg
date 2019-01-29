#include <iostream>
using namespace std;

// T(n): O(n); S(n): O(1);
int main(int argc, char const *argv[])
{
	int n, a[100];
	cin>>n;
	for(int i=0; i<n; i++)
		cin>>a[i];
	int pi=0, ni=1;
	while(pi<n && ni<n){
		if(a[pi]>0){
			pi+=2;
		}
		if(a[ni]<0){
			ni+=2;
		}
		if(a[pi]<0 && a[ni]>0){
			int temp=a[pi];
			a[pi]=a[ni];
			a[ni]=temp;
		}
	}
	for(int i=0; i<n; i++)
		cout<<a[i]<<" ";
	return 0;
}