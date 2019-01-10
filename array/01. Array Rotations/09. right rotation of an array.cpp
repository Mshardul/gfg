#include <iostream>
using namespace std;

/*
// T(n): O(n); S(n): O(1);
int main(int argc, char const *argv[])
{
	int n, a[1000], k;
	cin>>n;
	for(int i=0; i<n; i++)
		cin>>a[i];
	cin>>k;
	for(int i=n-k; i<(2*n)-k; i++)
		cout<<a[i%n];
	return 0;
}
*/

// T(n): O(n); S(n): O(1);
void ReverseArr(int a[], int l, int r){
	while(l<r){
		swap(a[l], a[r]);
		l++;
		r--;
	}
}

void Rotate(int a[], int k, int n){
	ReverseArr(a, 0, n-1);
	ReverseArr(a, 0, k-1);
	ReverseArr(a, k, n-1);
}

int main(int argc, char const *argv[])
{
	int n, a[1000], k;
	cin>>n;
	for(int i=0; i<n; i++)
		cin>>a[i];
	cin>>k;
	Rotate(a, k, n);
	for (int i = 0; i < n; ++i)
		cout<<a[i];
	return 0;
}