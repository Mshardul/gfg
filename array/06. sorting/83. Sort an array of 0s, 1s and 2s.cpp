#include<iostream>
using namespace std;

/*
//T(n): O(n); S(n): O(1);
int main(){
	int n;
	cin>>n;
	int a[n];
	for(int i=0; i<n; i++)
		cin>>a[i];
	int c0=0, c1=0, c2=0;
	for(int i=0; i<n; i++){
		if(a[i]==0)
			c0++;
		else if(a[i]==1)
			c1++;
		else
			c2++;
	}
	int i;
	for(i=0; i<c0; i++)
		cout<<"0 ";
	for(; i<c0+c1; i++)
		cout<<"1 ";
	for(; i<c0+c1+c2; i++)
		cout<<"2 ";
	cout<<endl;
	return 0;
}
*/

//using dutch national flag problem
//T(n)=O(n); S(n): O(1);
void Partition(int a[], int n){
	int l=0, m=0, h=n-1, mid=(l+h)/2;
	while(m<=h){
		if(a[m]==1)
			m++;
		else if(a[m]==2)
			swap(a[m], a[h--]);
		else
			swap(a[l++], a[m++]);
	}
	for(int i=0; i<n; i++)
		cout<<a[i]<<" ";
	cout<<endl;
}
int main(){
	int n;
	cin>>n;
	int a[n];
	for(int i=0; i<n; i++)
		cin>>a[i];
	Partition(a, n);
}