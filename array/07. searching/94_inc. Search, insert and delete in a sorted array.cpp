#include <iostream>
using namespace std;

//assuming no repetition
//something is wrong. check again.
int Search(int a[], int ele, int l, int r){
	if(l>=r)
		return -1;
	int mid=(l+r)/2;
	if(ele==a[mid])
		return mid;
	else if(ele<a[mid])
		return Search(a, ele, l, mid-1);
	else
		return Search(a, ele, mid+1, r);
}

int GetIndToInsert(int a[], int ele, int l, int r){
	if(ele<a[l])
		return l;
	else if(ele>a[r])
		return r+1;
	int mid=(l+r)/2;
	if((ele>=a[mid-1]) && (ele<=a[mid]))
		return mid;
	else if(ele<a[mid-1])
		return GetIndToInsert(a, ele, l, mid-1);
	return GetIndToInsert(a, ele, mid+1, r);
}

int Insert(int a[], int ele, int n){
	if(n>98)
		return 0;
	int ind=GetIndToInsert(a, ele, 0, n);
	for(int i=n-1; i>ind; i--)
		a[i]=a[i-1];
	a[ind]=ele;
	return 1;
}

int Delete(int a[], int ele, int n){
	int ind=Search(a, ele, 0, n-1);
	if(ind==-1)
		return 1;
	for(int i=ind; i<n-1; i++)
		a[i]=a[i+1];
	return 0;
}

void PrintArry(int a[], int n){
	cout<<n<<" ";
	for(int i=0; i<n; i++)
		cout<<a[i]<<" ";
	cout<<endl;
}

int main(int argc, char const *argv[])
{
	int n=0;
	int a[100];
	do{
		cout<<"1. insert\t2.delete\t3.search"<<endl;
		int menu, num;
		cin>>menu;
		cin>>num;
		switch(menu){
			case 1: 
			n+=Insert(a, num, n);
			PrintArry(a, n);
			break;
			case 2: 
			n-=Delete(a, num, n);
			PrintArry(a, n);
			break;
			case 3: 
			Search(a, num, 0, n-1);
			PrintArry(a, n);
			break;
			default: exit(0);
		}
	}while(1);
	return 0;
}