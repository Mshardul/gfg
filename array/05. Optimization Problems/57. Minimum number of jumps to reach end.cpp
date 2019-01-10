#include <iostream>
using namespace std;

//This is a DP sol
//T(n): O(n^2); S(n): O(1);
void Print(int a[], int n, int i){
	cout<<i<<": ";
	for(int i=0; i<n; i++)
		cout<<a[i]<<" ";
	cout<<endl;
}

int main(int argc, char const *argv[])
{
	int n;
	cin>>n;
	int a[n];
	for(int i=0; i<n; i++)
		cin>>a[i];
	for(int i=n-1; i>-1; i--){
		int k=a[i];
		if(i+k>=n)
			a[i]=1;
		else{
			int steps=n+1;
			for(int j=i+k; j>i; j--)
				steps=min(steps, 1+a[j]);
			a[i]=steps;
		}
		Print(a, n, i);
	}
	cout<<a[0]<<endl;
	return 0;
}