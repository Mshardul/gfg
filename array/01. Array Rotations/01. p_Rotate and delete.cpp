#include <iostream>
#include <list>
using namespace std;

//answer seems correct. but it is giving tle on gfg. >0.24sec
int main(int argc, char const *argv[])
{
    ios::sync_with_stdio(false); cin.tie(nullptr);
	int t; 
	cin>>t;
	while(t-->0){
		int n;
		long int a[101];
		int res[101];
		cin>>n;
		for(int i=0; i<n; i++)
			cin>>a[i];
		for(int i=0; i<n; i++)
			res[i]=1;
		int ind=n-1; //starting from this index to delete elements
		int to_del=1; //number of elements to skip
		int mid=(n%2==0)?n/2:(n/2)+1; //only this many elements to be deleted
		while(to_del<=mid){
			int i=ind-1;
			int count=0;
			while(1){
				if(i<0)
					i+=n;
				if(res[i]==1)
					count++;
				if(count==to_del){
					res[i]=0;
					int j=ind-1;
					while(1){ //get next available element
						if(j<0)
							j+=n;
						if(res[j]==1){
							ind=j;
							break;
						}
						j--;
					}
					to_del++;
					break;
				}
				i--;
			}
		}
		for(int i=0; i<n; i++){
			int index=(ind+1+i)%n;
			if(res[index]==1){
				cout<<a[index]<<endl;
				break;
			}
		}
	}
	return 0;
}