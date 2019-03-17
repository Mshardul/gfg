#include <iostream>
using namespace std;

// T(n): O(nq); S(n): O(1);
void rot(int a[], int l, int r){
	int size=r-l+1;
	int temp=a[r];
	int i;
	for(i=r; i>l; i--)
		a[i]=a[i-1];
	a[i]=temp;
}

int main(int argc, char const *argv[])
{
	int n, a[1000], q, l, r;
	cin>>n;
	for(int i=0; i<n; i++)
		cin>>a[i];
	cin>>q;
	for(int i=0; i<q; i++){
		cin>>l>>r;
		rot(a, l, r);
		for(int j=0; j<n; j++)
			cout<<a[j]<<" ";
	}
	return 0;
}