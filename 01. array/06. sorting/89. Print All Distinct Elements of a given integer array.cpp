#include <iostream>
#include <unordered_set>
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
	int l=0;
	cout<<a[0]<<" ";
	for(int i=1; i<n; i++){
		if(a[i]!=a[i-1])
			cout<<a[i]<<" ";
	}
	cout<<endl;
	return 0;
}
*/

int main(int argc, char const *argv[])
{
	int n, temp;
	cin>>n;
	unordered_set<int> a;
	int arr[n];
	for(int i=0; i<n; i++)
		cin>>arr[i];
	for(int i=0; i<n; i++){
		if(a.find(arr[i])==a.end()){
			a.insert(arr[i]);
			cout<<arr[i]<<" ";
		}
	}
	cout<<endl;
	return 0;
}