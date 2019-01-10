#include <iostream>
using namespace std;

/*
//T(n): O(n); S(n):O(1);
int main(int argc, char const *argv[])
{
	int n, a[100], max1=INT_MIN, max2=INT_MIN;
	cin>>n;
	for(int i=0; i<n; i++)
		cin>>a[i];
	for(int i=0; i<n; i++){
		if(a[i]>max1){
			max2=max1;
			max1=a[i];
		}
		else if(a[i]>max2)
			max2=a[i];
	}
	for(int i=0; i<n; i++)
		if(a[i]!=max1 && a[i]!=max2)
			cout<<a[i]<<" ";
	cout<<endl;
	return 0;
}
*/

//efficient than previous algo
//T(n): O(n); S(n): O(1)
int main(int argc, char const *argv[])
{
	int n, a[100], max1=INT_MIN, max2=INT_MIN;
	cin>>n;
	for(int i=0; i<n; i++)
		cin>>a[i];
	for(int i=0; i<n; i++){
		if(a[i]>max1){
			max2=max1;
			max1=a[i];
		}
		else if(a[i]>max2)
			max2=a[i];
	}
	for(int i=0; i<n; i++)
		if(a[i]<max2)
			cout<<a[i]<<" ";
	cout<<endl;
	return 0;
}