#include<iostream>
#include<vector>

using namespace std;

int squareSubMatrix(vector<vector<int> > vec, int n, int m){
	vector<vector<int> > dp;
	dp.resize(n, vector<int>(m));
	
	int ret = 0;
	for(int i=0; i<n; i++){
		for(int j=0; j<m; j++){
			if(i==0||j==0)
				dp[i][j] = vec[i][j];
			else{
				if(vec[i][j]==0)
					dp[i][j] = 0;
				else
					dp[i][j] = min(dp[i-1][j-1], min(dp[i-1][j], dp[i][j-1]))+1;
			}
			cout<<dp[i][j]<<" ";
			ret = max(ret, dp[i][j]);
		}
		cout<<endl;
	}
	return ret;
}

int main(int argc, char const *argv[]) {
	int n, m;
	cin>>n>>m;
	
	vector<vector<int> > vec;
	vec.resize(n, vector<int>(m));
	
	for(int i=0; i<n; i++){
		for(int j=0; j<m; j++)
			cin>>vec[i][j];
	}
	
	cout<<squareSubMatrix(vec, n, m)<<endl;
	return 0;
}