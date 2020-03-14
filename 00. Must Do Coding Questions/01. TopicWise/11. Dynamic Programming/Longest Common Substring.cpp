#include<iostream>
#include<vector>

using namespace std;

int lcs(string x, int n, string y, int m){
	vector<vector<int> > vec;
	vec.resize(n+1, vector<int>(m+1)); //n*m
	
	int ans = 0;
	
	for(int i=0; i<n; i++){
		for(int j=0; j<m; j++){
			if(x[i]==y[j]){
				vec[i+1][j+1] = 1+vec[i][j];
				if(vec[i+1][j+1]>ans)
					ans = vec[i+1][j+1];
			}else{
				vec[i+1][j+1] = 0;
			}
		}
	}
	
	return ans;
}

int main(int argc, char const *argv[]) {
	int t;
	cin>>t;
	while(t-->0){
		int n, m;
		cin>>n>>m;
		string x, y;
		cin>>x>>y;
		cout<<lcs(x, n, y, m)<<endl;
	}
	return 0;
}