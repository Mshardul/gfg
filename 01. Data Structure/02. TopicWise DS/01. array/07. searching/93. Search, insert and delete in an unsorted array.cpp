#include <iostream>
using namespace std;

int Insert(int a[], int ele, int n);
int Delete(int a[], int ele, int n);
int Search(int a[], int ele, int n);
void PrintArry(int a[], int n);

int Insert(int a[], int ele, int n){
	if(n>98){
		cout<<"array overflow"<<endl;
		return 0;
	}
	a[n]=ele;
	return 1;
}

int Delete(int a[], int ele, int n){
	if(n<1){
		cout<<"no element to delete";
		return 0;
	}
	int i=Search(a, ele, n);
	if(i!=-1){
		while(i<n-1){
			a[i]=a[i+1];
			i++;
		}
		cout<<"element deleted"<<endl;
		return 1;
	}
	return 0;
}

int Search(int a[], int ele, int n){
	int found=-1;
	for(int i=n-1; i>-1; i--){
		if(a[i]==ele){
			found=i;
			break;
		}
	}
	if(found==-1)
		cout<<"element not found";
	else
		cout<<"element found at index "<<found;
	cout<<endl;
	return found;
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
			Search(a, num, n);
			PrintArry(a, n);
			break;
			default: exit(0);
		}
	}while(1);
	return 0;
}