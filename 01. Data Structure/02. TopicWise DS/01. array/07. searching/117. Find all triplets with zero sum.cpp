#include <iostream>
using namespace std;

// T(n): O(n^2); S(n): O(1);
int Searchpair(int a[], int l, int r, int x, int y){
	while(l<r){
		if(a[l]+a[r]==x){
			cout<<y<<" "<<a[l]<<" "<<a[r]<<endl;
			return 1;
		}
		else if(a[l]+a[r]<x)
			l++;
		else
			r--;
	}
	return 0;
}
int main(int argc, char const *argv[])
{
	int n;
	cin>>n;
	int a[n];
	for(int i=0; i<n; i++)
		cin>>a[i];

	sort(a, a+n);

	int found=0;
	
	for(int i=0; i<n-2 && a[i]<=0; i++)
		found=found||Searchpair(a, i+1, n-1, (0-a[i]), a[i]);
	
	if(!found)
		cout<<"no such triplet found"<<endl;
	
	return 0;
}