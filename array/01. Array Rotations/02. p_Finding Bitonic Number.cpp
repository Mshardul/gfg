#include <iostream>
using namespace std;

int main(int argc, char const *argv[])
{
	int t;
	cin>>t;
	while(t-->0){
		int n, a[1000];
		cin>>n;
		for(int i=0; i<n; i++)
			cin>>a[i];
		int l=0, r=n-1, mid;
		while(l<r){
			mid=(l+r)/2;
			if(a[mid-1]<a[mid]){
				if(a[mid]>a[mid+1]){
					cout<<mid<<endl;
					break;
				}
				else
					l=mid+1;
			}
			else{
				if(a[mid-2]<a[mid-1]){
					cout<<mid-1<<endl;
					break;
				}
				else
					r=mid-1;
			}
		}
	}
	return 0;
}