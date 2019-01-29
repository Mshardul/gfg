#include <iostream>
using namespace std;

int GetMissingVal(int a[], int l, int r){
	if(l!=a[l])
		return l;
	int mid=(l+r)/2;
	if(a[mid]!=mid){
		if(mid>l && a[mid-1]!=mid-1)
			return GetMissingVal(a, l, mid-1);
		else
			return mid;
	}
	else{
		if(mid<r){
			if(a[mid+1]!=mid+1)
				return mid+1;
			else
				return GetMissingVal(a, mid+2, r);
		}
		else
			return -1;
	}
}
int main(int argc, char const *argv[])
{
	int n;
	cin>>n;
	int a[n];
	for(int i=0; i<n; i++)
		cin>>a[i];
	if(a[n-1]==n-1)
		cout<<n;
	else
		cout<<GetMissingVal(a, 0, n-1);
	return 0;
}