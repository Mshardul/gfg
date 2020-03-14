#include<iostream>
#include<vector>

using namespace std;

int islands(vector<vector<int> > vec){
	int n = vec.size();
	if(n==0)
		return 0;
	int m = vec[0].size();
	vector<vector<int> > dp;
	dp.resize(n, vector<int>(m, INT_MAX));
	
	for(int i=0; i<n; i++){
		if(vec[i][0]==1)
			dp[i][0] = m*i;
	}
	
	for(int i=0; i<m; i++){
		if(vec[0][i]==1)
			dp[0][i] = i;
	}
	
	for(int i=1; i<n; i++){
		for(int j=1; j<m; j++){
			if(vec[i][j]==0)
				continue;
			vec[i][j] = min(m*i+j, min(vec[i-1][j], vec[i][j-1]));
		}
	}
}

int main(int argc, char const *argv[]) {
	int n, m;
	cin>>n>>m;
	vector<vector<int> > vec;
	vec.resize(n, vector<int>(m));
	cout<<islands(vec)<<endl;
	return 0;
}