#include <iostream>
using namespace std;

/*
// T(n): O(n); S(n): O(n);
int main(int argc, char const *argv[])
{
	int n, a[100], b[100];
	cin>>n; 
	for(int i=0; i<n; i++)
		cin>>a[i];
	int l=0, r=n-1, ind=0;
	while(l<=r){
		b[2*ind]=a[r--];
		// if(l>=r)
		// 	break;
		b[2*ind+1]=a[l++];
		ind++;
	}
	for(int i=0; i<n; i++)
		cout<<b[i]<<" ";
	return 0;
}
*/

//T(n): O(n); S(n):O(1)
int main(int argc, char const *argv[])
{
	int n, a[100], max_ele=-1;
	cin>>n;
	for(int i=0; i<n; i++){
		cin>>a[i];
	}
	max_ele=a[n-1]+1;
	int l=0, r=n-1;
	int ind=0;
	while(l<=r){
		a[ind++]=a[l++]*max_ele+a[r--];
	}
	r=n-1;
	a[r]=a[--ind]/max_ele;
	if(n%2==0)
		a[--r]=a[ind]%max_ele;
	while(ind>0){
		ind--;
		a[--r]=a[ind]/max_ele;
		a[--r]=a[ind]%max_ele;
	}
	for(int i=0; i<n; i++)
		cout<<a[i]<<" ";
	return 0;
}