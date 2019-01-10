#include <iostream>
#include <vector>
using namespace std;

/*
//T(n) = O(log n); S(n) = O(1);
int GetPivot(int a[], int l, int r){
	if(l>r)
		return r;
	int mid = (l+r)/2;
	if(a[mid]>a[mid+1])
		return mid;
	if(a[l]>a[mid])
		return GetPivot(a, l, mid-1);
	return GetPivot(a, mid+1, r);
}

int BinarySearch(int a[], int ele, int l, int r){
	if(l>r)
		return 0;
	int mid = (l+r)/2;
	if(a[mid]==ele)
		return 1;
	if(ele<a[mid]){
		return BinarySearch(a, ele, l, mid-1);
	}
	return BinarySearch(a, ele, mid+1, r);
}

int main(int argc, char const *argv[])
{
	int n, a[1000], ele, mid, res;
	cin>>n;
	for(int i=0; i<n; i++)
		cin>>a[i];
	cin>>ele;
	if(a[0]<a[n-1])
		mid=n-1;
	else
		mid = GetPivot(a, 0, n-1);
	cout<<mid;
	if(ele<a[0])
		res = BinarySearch(a, ele, mid+1, n-1);
	else
		res = BinarySearch(a, ele, 0, mid);
	if(res)
		cout<<"element found";
	else
		cout<<"element not found";
	return 0;
}
*/

//T(n) = O(log n); S(n) = O(1);
int Search(vector<int>& a, int ele, int l, int r){
	cout<<"searching in "<<l<<" "<<r<<endl;
	if(l>r)
		return 0;
	int mid=(l+r)/2;
	cout<<mid<<endl;
	if(a[mid]==ele)
		return 1;
	if(a[l]<a[mid]){ //a[l to mid] is sorted
		// cout<<l<<" "<<mid<<" is sorted"<<endl;
		if(ele>=a[l] && ele<=a[mid-1])
			return Search(a, ele, l, mid-1);
		else
			return Search(a, ele, mid+1, r);
	}
	else{ //a[mid+1 to r] is sorted
		// cout<<mid+1<<" "<<r<<" is sorted"<<endl;
		if(ele>=a[mid+1] && ele<=a[r])
			return Search(a, ele, mid+1, r);
		else
			return Search(a, ele, l, mid-1);
	}
}
int main(int argc, char const *argv[])
{
	int n, input, ele;
	vector<int> v;
	cin>>n;
	for(int i=0; i<n; i++){
		cin>>input;
		v.push_back(input);
	}
	cin>>ele;
	int res = Search(v, ele, 0, n-1);
	if(res==1)
		cout<<"element found";
	else
		cout<<"element not found";
	return 0;
}