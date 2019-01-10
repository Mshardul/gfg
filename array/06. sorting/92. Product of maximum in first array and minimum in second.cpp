#include <iostream>
using namespace std;

// T(n): O(n); S(n): O(1);
int main(int argc, char const *argv[])
{
	int n, m;
	cin>>n;
	cin>>m;
	int a[n], b[m];
	for(int i=0; i<n; i++)
		cin>>a[i];
	for(int i=0; i<m; i++)
		cin>>b[i];
	int max=INT_MIN, min=INT_MAX;
	for(int i=0; i<n; i++){
		if(a[i]>max)
			max=a[i];
		if(b[i]<min)
			min=b[i];
	}
	cout<<max*min<<endl;
	return 0;
}