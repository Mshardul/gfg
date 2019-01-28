#include <iostream>
using namespace std;

// T(n): O(log n);
int GetFloor(int a[], int l, int r, int x){
	if(x<a[l])
		return l-1;
	if(x>=a[r])
		return r;
	int mid=(l+r)/2;
	if(a[mid]<=x && a[mid+1]>x)
		return mid;
	if(a[mid]<x)
		return GetFloor(a, mid+1, r, x);
	return GetFloor(a, l, mid, x);
}

int GetCeil(int a[], int l, int r, int x){
	if(x>a[r])
		return r+1;
	if(x<=a[l])
		return l;
	int mid=(l+r)/2;
	if(a[mid-1]<x && a[mid]>=x)
		return mid;
	if(a[mid-1]<x)
		return GetCeil(a, mid, r, x);
	return GetCeil(a, l, mid-2, x);
}

int main(int argc, char const *argv[])
{
	int n, x;
	cin>>n;
	int a[n];
	for(int i=0; i<n; i++)
		cin>>a[i];
	cin>>x;
	int f=GetFloor(a, 0, n-1, x);
	cout<<"floor: ";
	(f<0)?cout<<"doesnt exist":cout<<a[f];
	int c=GetCeil(a, 0, n-1, x);
	cout<<"; ceil: ";
	(c>=n)?cout<<"doesnt exist":cout<<a[c];
	cout<<endl;
	return 0;
}