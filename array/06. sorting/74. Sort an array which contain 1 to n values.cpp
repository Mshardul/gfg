#include <iostream>
using namespace std;

//although, as we have 1 to n numbers, we need not sort them at all.
//but if we have to:-
//T(n): O(n); S(n): O(1);
int main(int argc, char const *argv[])
{
	int n;
	cin>>n;
	int a[n];
	for(int i=0; i<n; i++)
		cin>>a[i];
	int i=0;
	while(i<n){
		if(a[i]==i+1)
			i++;
		else{
			int ind=i, temp;
			while(a[ind]!=ind+1){
				temp=a[ind]-1;
				a[ind]=ind+1;
				ind=temp;
			}
		}
	}
	for(i=0; i<n; i++)
		cout<<a[i]<<" ";
	cout<<endl;
	return 0;
}