#include<vector>
#include<iostream>

using namespace std;

int main(int argc, char const *argv[]) {
	int t;
	cin>>t;
	while(t-->0){
		int n, m;
		cin>>n>>m;
		vector<long> a(n);
		vector<long> b(m);
		for(int i=0; i<n; i++)
			cin>>a[i];
		for(int i=0; i<m; i++)
			cin>>b[i];
	}
	return 0;
}