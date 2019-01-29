#include <iostream>
using namespace std;

//T(n): O(n); S(n): O(1);
int main(int argc, char const *argv[])
{
	int n;
	cin>>n;

	int a[n], b[n];
	for(int i=0; i<n; i++)
		cin>>a[i];
	for(int i=0; i<n; i++)
		cin>>b[i];

	int ind1=0, ind2=0;
	while(ind1<n){
		if(a[ind1]>b[ind2])
			ind2++;
		else{
			if(a[ind1]<b[ind2])
				cout<<a[ind1]<<" ";
			ind1++;
		}
	}
	cout<<endl;
	return 0;
}