#include <iostream>
using namespace std;

//T(n): O(log n); S(n): O(1);
int BinarySearch(int a[], int l, int r, int ele){
	if(l>r)
		return -1;
	int mid=(l+r)/2;
	if(ele<a[mid])
		return BinarySearch(a, l, mid-1, ele);
	return BinarySearch(a, mid+1, r, ele);
}
int Search(int a[], int l, int r, int ele){
	if(a[l]==INT_MIN && a[r]==INT_MIN)
		return -1;
	else if(a[l]==ele)
		return l;
	else if(a[r]==ele)
		return r;
	else if(ele>a[l] && ele<a[r])
		return BinarySearch(a, l, r, ele);
	else //ele>a[r]
		return Search(a, r+1, 2*r, ele);
}

int main(int argc, char const *argv[])
{
	int a[1000]={INT_MIN};
	int temp, i=0, ele;
	do{
		cin>>temp;
		a[i++]=temp;
	}while(temp!=-1);
	
	cin>>ele;
	
	int gotit=-1;
	gotit=Search(a, 0, 1, ele);
	if(gotit==-1)
		cout<<"element not found"<<endl;
	else
		cout<<"element found @ "<<gotit<<endl;
	return 0;
}