#include <iostream>
using namespace std;

//T(n): O(n); S(n): O(1);
int main(int argc, char const *argv[])
{
	int n, a[1000], count=0;
	cin>>n;
	for(int i=0; i<n; i++)
		cin>>a[i];
	for(int i=0; i<n; i++){
		if(a[i]==0)
			count++;
		else
			cout<<a[i]<<" ";
	}
	for(int i=0; i<count; i++)
		cout<<"0 ";
	return 0;
}