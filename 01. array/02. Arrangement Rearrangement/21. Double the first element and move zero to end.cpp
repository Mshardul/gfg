#include <iostream>
using namespace std;

// T(n): O(n); S(n)=O(1);
int main(int argc, char const *argv[])
{
	int n, a[100];
	cin>>n;
	for(int i=0; i<n; i++)
		cin>>a[i];
	int prev_val=0, prev_ind=-1;
	for(int i=0; i<n; i++){
		if(a[i]!=0){
			if(prev_ind==-1){
				prev_ind=i;
				prev_val=a[i];
			}
			else{
				if(a[i]==prev_val){
					a[prev_ind]*=2;
					a[i]=0;
					prev_ind=-1;
					prev_val=0;
				}
				else{
					prev_ind=i;
					prev_val=a[i];
				}
			}
		}
	}
	int curr_ind=0, val_ind=0;
	for(int i=0; i<n; i++){
		if(a[i]!=0){
			a[curr_ind++]=a[i];
		}
	}
	while(curr_ind<n)
		a[curr_ind++]=0;
	for(int i=0; i<n; i++)
		cout<<a[i]<<" ";
	cout<<endl;
	return 0;
}