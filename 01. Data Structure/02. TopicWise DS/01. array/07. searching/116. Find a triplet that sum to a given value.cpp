#include <iostream>
using namespace std;

/*
//T(n): O(n^2 log n); S(n): O(1);
int Search(int a[], int l, int r, int x){
	if(l>r)
		return -1;
	int mid=(l+r)/2;
	if(a[mid]==x)
		return mid;
	else if(a[mid]>x)
		return Search(a, l, mid-1, x);
	return Search(a, mid+1, r, x);
}
int main(int argc, char const *argv[])
{
	int n, sum;
	cin>>n;
	cin>>sum;
	int a[n];
	for(int i=0; i<n; i++)
		cin>>a[i];
	sort(a, a+n);
	for(int i=0; i<n-2; i++){
		for(int j=i+1; j<n-1; j++){
			int k = Search(a, j+1, n-1, (sum-(a[i]+a[j])));
			if(k!=-1)
				cout<<a[i]<<" "<<a[j]<<" "<<a[k];
		}
	}
	return 0;
}
*/

//using hashing - useful for smaller numbers;
//T(n): O(n^2); S(n): O(max(a[]))
int main(int argc, char const *argv[])
{
	int n, sum;
	cin>>n;
	cin>>sum;
	int a[n];
	for(int i=0; i<n; i++)
		cin>>a[i];
	int max=a[0], min=a[0];
	for(int i=1; i<n; i++){
		if(a[i]>max)
			max=a[i];
		if(a[i]<min)
			min=a[i];
	}

	int b[max-min+1];

	for(int i=0; i<max-min+1; i++)
		b[i]=0;
	for(int i=0; i<n; i++){
		b[a[i]-min]=1;
	}

	// for(int i=0; i<max-min+1; i++)
	// 	cout<<b[i]<<" ";
	for(int i=0; i<n; i++){
		b[a[i]-min]=0;
		for(int j=i+1; j<n; j++){
			b[a[j]-min]=0;
			int toFind=sum-(a[i]+a[j])-min;
			if(b[toFind]==1)
				cout<<a[i]<<" "<<a[j]<<" "<<toFind+1<<endl;
			b[a[j]-min]=1;
		}
		b[a[i]-min]=1;
	}


	return 0;
}