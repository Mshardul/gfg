#include <iostream>
using namespace std;

// T(n): O(n); S(n): O(1);
int main(int argc, char const *argv[])
{
	int n;
	cin>>n;
	int arr[n];
	int new_n=0;
	for(int i=1; i<n; i++)
		new_n+=i;
	int new_arr[new_n];
	for(int i=0; i<n; i++)
		cin>>new_arr[i];
	arr[0]=(new_arr[0]+new_arr[1]-new_arr[n-1])/2;
	for(int i=1; i<n; i++)
		arr[i]=new_arr[i-1]-arr[0];
	for(int i=0; i<n; i++)
		cout<<arr[i]<<" ";
	cout<<endl;
	return 0;
}