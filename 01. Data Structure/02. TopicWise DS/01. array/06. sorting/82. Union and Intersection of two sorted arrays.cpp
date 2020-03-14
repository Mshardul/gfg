#include <iostream>
using namespace std;

//for unsorted array, we can just sort the arrays. T(n): O(max(n log n, m log m)); S(n): O(1);
//no condition of duplicacy in case of union
// T(n): O(m+n); S(n): O(1);
void Union(int a[], int b[], int n, int m){
	int i=0, j=0;
	while(i<n && j<m){
		if(a[i]==b[j]){
			cout<<a[i++]<<" ";
			j++;
		}
		else if(a[i]<b[j])
			cout<<a[i++]<<" ";
		else
			cout<<b[j++]<<" ";
	}
	while(i<n)
		cout<<a[i++]<<" ";
	while(j<m)
		cout<<b[j++]<<" ";
	cout<<endl;
}

void Intersection(int a[], int b[], int n, int m){
	int i=0, j=0;
	while(i<n&&j<m){
		if(a[i]==b[j]){
			cout<<a[i++]<<" ";
			j++;
		}
		else if(a[i]<b[j])
			i++;
		else
			j++;
	}
	cout<<endl;
}

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
	// sort(a, a+n);
	// sort(b, b+n);
	Union(a, b, n, m);
	Intersection(a, b, n, m);
	return 0;
}