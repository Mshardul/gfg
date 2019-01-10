//this is the rank question

#include <iostream>
#include <bits/stdc++.h>
using namespace std;

/*
//sort and get (k-1)th element
// T(n): O(n + k log n); S(n): O(n)
int main(int argc, char const *argv[])
{
	int n, a[100], k;
	cin>>n;
	for(int i=0; i<n; i++)
		cin>>a[i];
	cin>>k;
	sort(a, a+n);
	cout<<a[k-1];
	return 0;
}
*/

/*
//build min heap and call extractMin() k times;
//similarly, we can also use maxheap and get (n-k)th largest element
//which ds to use, depends upon the value of k
//T(n)=O(n); S(n)=O(n);
class MinHeap
{
	int arr[100];
	int capacity;
	int size;

public:
	MinHeap(int a[], int n);
	void MinHeapify(int i);
	int parent(int i){return (i-1)/2; }
	int lc(int i){return (2*i)+1; }
	int rc(int i){return (2*i)+2; }
	int extractMin();
	int getMin(){return arr[0]; };
	void PrintHeap();
};

MinHeap::MinHeap(int a[], int n){
	size=n;
	for(int i=0; i<n; i++)
		arr[i]=a[i];
	// PrintHeap();
	int i=(size-1)/2;
	while(i>=0){
		MinHeapify(i);
		i--;
	}
}

int MinHeap::extractMin(){
	if(size==0)
		return INT_MAX;
	int root=arr[0];
	if(size>0){
		arr[0]=arr[size-1];
		MinHeapify(0);
	}
	size--;
	PrintHeap();
	return root;
}

void MinHeap::MinHeapify(int i){
	int l=lc(i);
	int r=rc(i);
	int smallest=i;
	if(l<size && arr[l]<arr[smallest])
		smallest=l;
	if(r<size && arr[r]<arr[smallest])
		smallest=r;
	if(smallest!=i){
		swap(arr[i], arr[smallest]);
		MinHeapify(smallest);
	}

}

void MinHeap::PrintHeap(){
	for(int i=0; i<size; i++)
		cout<<arr[i]<<" ";
	cout<<endl;
}

int main(int argc, char const *argv[])
{
	int n, a[100], k;
	cin>>n;
	for(int i=0; i<n; i++)
		cin>>a[i];
	cin>>k;
	MinHeap mh(a, n);
	mh.PrintHeap();
	for(int i=1; i<k; i++){
		mh.extractMin();
	}
	int res=mh.getMin();
	cout<<res;
	return 0;
}
*/

/*
//quick sort implementation
//check only for kth pivot element
//only need to go for either left or right subarray
//T(n): θ(n); T(n): O(n^2); S(n): O(n)
int kthSmallest(int arr[], int l, int r, int k) 
{ 
	if (k>0 && k<=r-l+1) { 
		int pos = partition(arr, l, r);
		if (pos-l == k-1)
			return arr[pos];
		if (pos-l > k-1)
			return kthSmallest(arr, l, pos-1, k);
		return kthSmallest(arr, pos+1, r, k-pos+l-1); 
	}
	return INT_MAX; 
} 
  
void swap(int *a, int *b) {
	int temp = *a; 
	*a = *b; 
	*b = temp; 
}
  
int partition(int arr[], int l, int r){ // Standard partition process of QuickSort().
	int pivot = arr[r], i = l; 
	for (int j = l; j <= r - 1; j++){ 
		if (arr[j] <= pivot){ 
			swap(&arr[i], &arr[j]); 
			i++; 
		}
	}
	swap(&arr[i], &arr[r]); 
	return i; 
}

int main() 
{ 
	int n, a[100], k;
	cin>>n;
	for(int i=0; i<n; i++)
		cin>>a[i];
	cin>>k;
	cout<<kthSmallest(arr, 0, n-1, k); 
	return 0; 
}
*/

/*
//get better pivot element for previous algo
int getMedian(int a[], int n){
	if(l>n)
		return -1;
	if(n-l+1>5)
		n=l+5;
	sort(a, a+n);
	return a[n/2];
}
int kthSmallest(int a[], int l, int r, int k){
	if(k<=0||k<=r-l+1)
		return INT_MAX;
	int x=0;
	int i=0;
	int medIndex;
	for(i=0; i<r/5; i++)
		a[++x]=getMedian(a+l+i*5, a+l+5+i*5);
	if(i*5<r)
		a[++x]=getMedian(a+l+i*5, a+r);
	if(x>0)
		medIndex=kthSmallest(a, 0, x);
	else
		medIndex=a[x];
	int pos=partition(a, l, r, medIndex);
	if(pos-l==k-1)
		return arr[pos];
	else if(pos-l>k-1)
		return kthSmallest(a, l, pos-1, k);
	else return kthSmallest(a, pos+1, r, k-pos+l-1);
}

void swap(int *a, int *b){
	int temp = *a;
	*a = *b;
	*b = temp;
}

int partition(int arr[], int l, int r, int x) 
{
	int i;
	for (i=l; i<r; i++) 
		if (arr[i] == x) 
			break; 
	swap(&arr[i], &arr[r]); 
	i = l; 
	for (int j = l; j <= r - 1; j++){ 
		if (arr[j] <= x){
			swap(&arr[i], &arr[j]); 
			i++; 
		} 
	}
	swap(&arr[i], &arr[r]); 
	return i; 
}

int main(int argc, char const *argv[])
{
	int n, a[100];
	cin>>n;
	for(int i=0; i<n; i++)
		cin>>a[i];
	kthSmallest(a, 0, n);
	return 0;
}
*/

//using c++ stl - set //is sorted always
//set uses bst internally
//T(n): O(n log n)
int main(int argc, char const *argv[])
{
	int n, k, temp;
	set<int> s;
	cin>>n;
	for(int i=0; i<n; i++){
		cin>>temp;
		s.insert(temp);
	}
	cin>>k;
	auto it=s.begin();
	for(int i=0; i<n; i++){
		cout<<*it<<" ";
		it++;
	}
	it=s.begin();
	for(int i=0; i<k-1; i++)
		it++;
	cout<<*it;

	return 0;
}