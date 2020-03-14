#include<iostream>
#include<vector>

using namespace std;

void Print2D(vector<vector<int> > vec){
	int n = vec.size();
	for(int i=0; i<n; i++){
		int m = vec[i].size();
		for(int j=0; j<m; j++)
			cout<<vec[i][j]<<" ";
		cout<<endl;
	}
	cout<<"-----------------\n";
}

int Dist(string x, int n, string y, int m){
	vector<vector<int> > dp;
	dp.resize(n+1, vector<int>(m+1));
	
	for(int i=0; i<n; i++)
		dp[i+1][0] = i+1;
	for(int i=0; i<m; i++)
		dp[0][i+1] = i+1;
		
	for(int i=0; i<n; i++){
		for(int j=0; j<m; j++){
			if(x[i]==y[j]){
				dp[i+1][j+1] = dp[i][j];
			}else{
				int insert = min(dp[i][j+1], dp[i+1][j]);
				int replace = dp[i][j];
				dp[i+1][j+1] = 1+min(insert, replace);
			}
		}
		// Print2D(dp);
	}
	return dp[n][m];
}

int main(int argc, char const *argv[]) {
	int t;
	cin>>t;
	while(t-->0){
		int n, m;
		cin>>n>>m;
		string x, y;
		cin>>x>>y;
		cout<<Dist(x, n, y, m)<<endl;
	}
	return 0;
}