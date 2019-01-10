#include <iostream>
using namespace std;

// T(n): O(n logn); S(n):O(n);
int main(int argc, char const *argv[])
{
	int n, a[100];
	cin>>n;
	for(int i=0; i<n; i++)
		cin>>a[i];
	sort(a, a+n);
	int b[100];
	int l=0, r=n-1, b_ind=0;
	while(l<=r){
		b[2*b_ind]=a[r--];
		b[2*b_ind+1]=a[l++];
		b_ind++;
	}
	for(int i=0; i<n; i++)
		cout<<b[i]<<" ";
	cout<<endl;
	return 0;
}