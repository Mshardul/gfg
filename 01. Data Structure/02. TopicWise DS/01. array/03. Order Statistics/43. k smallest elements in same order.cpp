#include <iostream>
using namespace std;

/*
// T(n): O(n log n); S(n): O(n);
bool BinarySearch(int a[], int ele, int l, int r){
	if(l>r)
		return false;
	int mid=(l+r)/2;
	if(a[mid]>ele)
		return BinarySearch(a, ele, l, mid-1);
	if(a[mid]<ele)
		return BinarySearch(a, ele, mid+1, r);
	return true;
}
int main(int argc, char const *argv[])
{
	int n, k;
	cin>>n;
	int a[n], b[n];
	for(int i=0; i<n; i++)
		cin>>a[i];
	for(int i=0; i<n; i++)
		b[i]=a[i];
	sort(b, b+n);
	cin>>k;
	for(int i=0; i<n; i++){
		if(a[i]<b[k] && BinarySearch(b, a[i], 0, k))
			cout<<a[i]<<" ";
	}
	cout<<endl;
	return 0;
}
*/

//using insertion sort technique
//T(n):O(n^2); S(n):O(1);
void Print(int a[], int n){
	for(int i=0; i<n; i++)
		cout<<a[i]<<" ";
	cout<<endl;
}
int main(int argc, char const *argv[])
{
	int n, k;
	cin>>n;
	int a[n];
	for(int i=0; i<n; i++)
		cin>>a[i];
	cin>>k;
	for(int i=k; i<n; i++){
		int max_val=a[k-1];
		int pos=k-1;
		int j;
		for(j=k-2; j>-1; j--){
			if(a[j]>max_val){
				max_val=a[j];
				pos=j;
			}
		}
		j=pos;
		while(j<k-1){
			a[j]=a[j+1];
			j+=1;
		}
		a[j]=a[i];
		Print(a, n);
	}
	return 0;
}