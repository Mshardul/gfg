#include <iostream>
using namespace std;

// T(n): O(log n); S(n): O(log n);
int BinarySearch(int a[], int l, int r){
	if(a[l]<a[r])
		return a[l];
	int mid = (l+r)/2;
	if(a[mid]>a[mid+1])
		return a[mid+1];
	if(a[mid]<a[mid-1])
		return a[mid];
	if(a[mid]>a[0])
		return BinarySearch(a, mid+1, r);
	return BinarySearch(a, l, mid-1);
}

int main(int argc, char const *argv[])
{
	int n, a[1000], min;
	cin>>n;
	for(int i=0; i<n; i++)
		cin>>a[i];
	int x = BinarySearch(a, 0, n-1);
	cout<<x;
	return 0;
}