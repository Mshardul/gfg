#include <iostream>
using namespace std;

/*
// T(n): O(n); S(n): O(1);
int main(int argc, char const *argv[])
{
	int n;
	cin>>n;
	int a[n];
	for(int i=0; i<n; i++)
		cin>>a[i];
	int num_0=0;
	for(int i=0; i<n; i++){
		if(a[i]==0)
			num_0++;
	}
	for(int i=0; i<num_0; i++)
		a[i]=0;
	for(int i=num_0; i<n; i++)
		a[i]=1;
	for(int i=0; i<n; i++)
		cout<<a[i]<<" ";
	cout<<endl;
	return 0;
}
*/

//in one iteration only
// T(n): O(n); S(n): O(1);
int main(int argc, char const *argv[])
{
	int n;
	cin>>n;
	int a[n];
	for(int i=0; i<n; i++)
		cin>>a[i];
	int l=0, r=n-1;
	while(l<=r){
		if(a[l]==0)
			l++;
		else{
			if(a[r]==1)
				r--;
			else{
				swap(a[l], a[r]);
				l++;
				r--;
			}
		}
	}
	for(int i=0; i<n; i++)
		cout<<a[i]<<" ";
	cout<<endl;
	return 0;
}