#include<iostream>
#include<vector>

using namespace std;

void Print2D(vector<vector<int> > dp){
	int n = dp.size();
	for(int i=0; i<n; i++){
		int m = dp[i].size();
		for(int j=0; j<m; j++)
			cout<<dp[i][j]<<" ";
		cout<<endl;
	}
}

int minCost(vector<vector<int> > vec, int n, int m){
	vector<vector<int> > dp;
	dp.resize(n, vector<int> (m));
	dp[0][0] = vec[0][0];
	
	for(int i=1; i<n; i++)
		dp[i][0] = dp[i-1][0] + vec[i][0];
	for(int j=1; j<m; j++)
		dp[0][j] = dp[0][j-1] + vec[0][j];
		
	for(int i=1; i<n; i++){
		for(int j=1; j<m; j++){
			dp[i][j] = vec[i][j] + min(dp[i-1][j-1], min(dp[i-1][j], dp[i][j-1]));
		}
	}
	
	Print2D(dp);
	return dp[n-1][m-1];
}

int main(int argc, char const *argv[]) {
	int n, m;
	cin>>n>>m;
	
	vector<vector<int> > vec;
	vec.resize(n, vector<int> (m));
	
	for(int i=0; i<n; i++){
		for(int j=0; j<m; j++)
			cin>>vec[i][j];
	}
	
	cout<<minCost(vec, n, m)<<endl;
	return 0;
}