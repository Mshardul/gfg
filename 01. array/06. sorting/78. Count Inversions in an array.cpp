#include <iostream>
using namespace std;

/*
// T(n): O(n^2); S(n): O(1);
int main(int argc, char const *argv[])
{
	int n;
	cin>>n;
	int a[n];
	for(int i=0; i<n; i++)
		cin>>a[i];
	int ans=0;
	for(int i=0; i<n; i++)
		for(int j=i; j<n; j++)
			if(a[j]<a[i])
				ans++;
	cout<<ans<<endl;
	return 0;
}
*/

//using merge sort algo
//T(n): O(n log n); S(n): O(n)
int Merge(int a[], int b[], int l, int mid, int r){
	int ans=0;
	int i=l, j=mid;
	int ind=l;
	while(i<mid && j<=r){
		if(a[i]<=a[j])
			b[ind++]=a[i++];
		else{
			b[ind++]=a[j++];
			ans+=mid-i;
		}
	}
	while(i<mid)
		b[ind++]=a[i++];
	while(j<=r)
		b[ind++]=a[j++];
	for(i=l; i<=r; i++)
		a[i]=b[i];
	return ans;
}
int MergeSort(int a[], int b[], int l, int r){
	if(l>=r)
		return 0;
	int mid=(l+r)/2;
	int ans=MergeSort(a, b, l, mid);
	ans+=MergeSort(a, b, mid+1, r);
	ans+=Merge(a, b, l, mid+1, r);
	return ans;
}
int main(int argc, char const *argv[])
{
	int n;
	cin>>n;
	int a[n], b[n];
	for(int i=0; i<n; i++)
		cin>>a[i];
	int ans = MergeSort(a, b, 0, n-1);
	cout<<ans<<endl;
	return 0;
}