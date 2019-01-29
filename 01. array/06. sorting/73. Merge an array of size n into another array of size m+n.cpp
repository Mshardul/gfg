#include <iostream>
using namespace std;

// T(n): O(n+m); S(n): O(n+m);
int main(int argc, char const *argv[])
{
	int n, m;
	cin>>n;
	cin>>m;
	int a[n], b[m], c[n+m];
	for(int i=0; i<n; i++)
		cin>>a[i];
	for(int i=0; i<m; i++)
		cin>>b[i];
	int i=0, j=0, k=0;
	while(i<n && j<m){
		if(a[i]<b[j])
			c[k++]=a[i++];
		else if(a[i]>b[j])
			c[k++]=b[j++];
		else{
			c[k++]=a[i++];
			c[k++]=b[j++];
		}
	}
	while(i<n)
		c[k++]=a[i++];
	while(j<m)
		c[k++]=b[j++];
	for(i=0; i<n+m; i++)
		cout<<c[i]<<" ";
	cout<<endl;
	return 0;
}