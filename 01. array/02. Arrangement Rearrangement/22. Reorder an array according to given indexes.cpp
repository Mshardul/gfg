#include <iostream>
using namespace std;

/*
// T(n): O(n); S(n):O(n);
int main(int argc, char const *argv[])
{
	int n, a[100], ind[100], b[100];
	cin>>n;
	for(int i=0; i<n; i++)
		cin>>a[i];
	for(int i=0; i<n; i++)
		cin>>ind[i];
	for(int i=0; i<n; i++)
		b[i]=a[ind[i]];
	for(int i=0; i<n; i++)
		cout<<b[i];
	return 0;
}
*/
 
int main() 
{ 
	int n, arr[100], index[100];
	cin>>n;
	for(int i=0; i<n; i++)
		cin>>arr[i];
	for(int i=0; i<n; i++)
		cin>>index[i];
	for (int i=0; i<n; i++) {
		while (index[i] != i) { 
			int  prev_i  = index[index[i]]; 
			char prev_v  = arr[index[i]];
			arr[index[i]] = arr[i]; 
			index[index[i]] = index[i];
			index[i] = prev_i; 
			arr[i]   = prev_v; 
		} 
	} 
	for (int i=0; i<n; i++) 
		cout << arr[i] << " "; 
	return 0; 
} 
