#include <iostream>
using namespace std;
 
//wrong solution
int BinarySearch(int a[], int l, int r, int ele){ //for bitonic, we should have 2 different binary search methods - one for increasing sequence and another for decreasing sequence.
	cout<<l<<" "<<r<<endl;
	if(l>r)
		return -1;
	int mid=(l+r)/2;
	if(a[mid]==ele)
		return mid;
	else if(ele<a[mid])
		return BinarySearch(a, l, mid-1, mid);
	else
		return BinarySearch(a, mid+1, r, mid);
}
int main(int argc, char const *argv[])
{
	int t;
	cin>>t;
	while(t-->0){
		int n, a[1000], ele;
		cin>>n;
		for(int i=0; i<n; i++)
			cin>>a[i];
		cin>>ele;
		int l=0, r=n-1, mid, found=0;

		while(l<r){
			mid=(l+r)/2;
			if(a[mid-1]<a[mid]){
				if(a[mid]>a[mid+1]){
					// cout<<mid<<endl;
					found=1;
					break;
				}
				else
					l=mid+1;
			}
			else{
				if(a[mid-2]<a[mid-1]){
					// cout<<mid-1<<endl;
					found=1;
					break;
				}
				else
					r=mid-1;
			}
		}
		if(found==0){
			if(a[0]<a[n-1])
				mid=n-1;
			else
				mid=0;
		}
		int ans=BinarySearch(a, 0, mid, ele);
		if(ans==-1){
			ans=mid+BinarySearch(a, mid+1, n-1, ele);
		}
		cout<<ans<<endl;
	}
	return 0;
}