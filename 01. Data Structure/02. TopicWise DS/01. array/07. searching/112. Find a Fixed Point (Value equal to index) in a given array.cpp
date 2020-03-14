#include <iostream>
using namespace std;

/*
//T(n): O(n); S(n): O(1);
int main(int argc, char const *argv[])
{
	int n;
	cin>>n;
	int a[n];
	for(int i=0; i<n; i++)
		cin>>a[i];
	for(int i=0; i<n; i++)
		if(i>0 && a[i]==i)
			cout<<a[i]<<" ";
	cout<<endl;
	return 0;
}
*/

//using binary search: for increasing array
//T(n): O(n log n); S(n): O(1);
int Search(int a[], int l, int r){
	if(l>r)
		return -1;
	int mid=(l+r)/2;
	if(a[mid]==mid)
		return mid;
	else if(a[mid]<mid)
		return Search(a, mid+1, r);
	return Search(a, l, mid-1);
}

int main(int argc, char const *argv[])
{
	int n;
	cin>>n;
	int a[n];
	for(int i=0; i<n; i++)
		cin>>a[i];
	cout<<Search(a, 0, n-1);
	return 0;
}