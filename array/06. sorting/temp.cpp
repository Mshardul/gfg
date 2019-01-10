#include<iostream>
using namespace std;
int main()
 {
	int t;
	cin>>t;
	while(t-->0){
	    int n, sum;
	    cin>>n;
	    int a[n];
	    for(int i=0; i<n; i++)
	        cin>>a[i];
	    cin>>sum;
	    int l=0, r=n-1, found=0;
	    while(l<r){
	        if(a[l]+a[r]==sum){
	            found=1;
	            cout<<a[l++]<<" "<<a[r--]<<" "<<sum<<endl;
	        }
	        else if(a[l]+a[r]<sum)
	            l++;
	        else
	            r--;
	    }
	    if(found==0)
	        cout<<"-1"<<endl;
	}
	return 0;
}