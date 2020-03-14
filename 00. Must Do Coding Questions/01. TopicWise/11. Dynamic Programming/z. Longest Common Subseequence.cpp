#include<iostream>
#include<vector>

using namespace std;

void Print(vector<vector<int> > dp){
	int n = dp.size();
	for(int i=0; i<n; i++){
		int m = dp[i].size();
		for(int j=0; j<m; j++)
			cout<<dp[i][j]<<" ";
		cout<<endl;
	}
}

int lcs(string x, string y){
	int n = x.size();
	int m = y.size();
	
	vector<vector<int> > dp;
	dp.resize(n+1, vector<int>(m+1));
	
	for(int i=0; i<n; i++){
		for(int j=0; j<m; j++){
			if(x[i]==y[j]){
				dp[i+1][0] = 1;
				dp[0][j+1] = 1;
			}
		}
	}
	
	for(int i=0; i<n; i++){
		for(int j=0; j<m; j++){
			if(x[i]==y[j]){
				dp[i+1][j+1] = 1+dp[i][j];
			}else{
				dp[i+1][j+1] = max(dp[i][j+1], dp[i+1][j]);
			}
		}
	}
	
	Print(dp);
	return dp[n][m];
}

int main(int argc, char const *argv[]) {
	int t;
	cin>>t;
	while(t-->0){
		int n, m;
		cin>>n>>m;
		
		string x;
		cin>>x;
		
		string y;
		cin>>y;
		
		cout<<lcs(x, y)<<endl;
	}
	return 0;
}