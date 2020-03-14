#include <iostream>
using namespace std;

// T(n): O(m*n), θ(m+n); S(n): O(1);
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
	int ind_a=0, ind_b=0;
	while(ind_a<n){
		if(a[ind_a]<=b[ind_b])
			ind_a++;
		else{
			int temp=ind_b;
			int to_rep=b[temp];
			while(temp<m-1){
				if(b[temp+1]>=a[ind_a])
					break;
				b[temp]=b[temp+1];
				temp++;
			}
			b[temp]=a[ind_a];
			a[ind_a]=to_rep;
			// ind_b++;
			ind_a++;
		}
	}
	for(int i=0; i<n; i++)
		cout<<a[i]<<" ";
	cout<<endl;
	for(int i=0; i<m; i++)
		cout<<b[i]<<" ";
	cout<<endl;
	return 0;
}