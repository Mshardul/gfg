#include<iostream>
using namespace std;

int GetIndex(int a[], int l, int r){
	if(l>r)
		return 0;
	int mid = (l+r)/2;
	if(a[mid]<a[mid-1])
		return mid;
	else
		if(a[mid]>a[0])
			return GetIndex(a, mid+1, r);
		return GetIndex(a, l, mid-1);
}

int main(int argc, char const *argv[])
{
	int n, a[1000], res;
	cin>>n;
	for(int i=0; i<n; i++){
		cin>>a[i];
	}
	cout<<GetIndex(a, 0, n)<<endl;
	return 0;
}