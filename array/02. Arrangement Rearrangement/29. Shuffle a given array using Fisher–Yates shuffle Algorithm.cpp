#include <iostream>
#include <stdlib.h>
using namespace std;

void PrintArr(int a[], int n){
	for(int i=0; i<n; i++)
		cout<<a[i]<<" ";
	cout<<endl;
}
int main(int argc, char const *argv[])
{
	int n, a[100];
	cin>>n;
	for(int i=0; i<n; i++)
		cin>>a[i];
	int r=n-1;
	while(r>0){
		int random=rand()%(r+1);
		int temp=a[random];
		a[random]=a[r];
		a[r]=temp;
		r--;
	}
	PrintArr(a, n);
	return 0;
}