#include <iostream>
using namespace std;

T(n): O(n); S(n): O(1);
int main(int argc, char const *argv[])
{
	int n;
	cin>>n;
	int a[n];
	for(int i=0; i<n; i++)
		cin>>a[i];
	int leader=a[n-1], i=n-2;
	cout<<a[n-1]<<" ";
	do{
		if(leader<a[i]){
			leader=a[i];
			cout<<leader<<" ";
		}
		i--;
	}while(i>0);
	cout<<endl;
	return 0;
}