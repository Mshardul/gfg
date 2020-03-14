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
}

/*
int binomial(int n, int k){
	vector<vector<int> > dp;
	dp.resize(n+1, vector<int> (k+1));
	
	for(int i=0; i<=n; i++)
		dp[i][0] = 1;
	for(int i=0; i<=min(n, k); i++)
		dp[i][i] = 1;
		
	for(int i=1; i<=n; i++){
		for(int j=1; j<=k; j++){
			dp[i][j] = dp[i-1][j-1] + dp[i-1][j];
		}
	}
	Print2D(dp);
	return dp[n][k];
}
*/

void Print(vector<int> vec){
	int n = vec.size();
	for(int i=0; i<n; i++)
		cout<<vec[i]<<" ";
	cout<<endl;
}

int binomial(int n, int k){
	vector<int> dp(k+1);
	dp[0] = 1;
	for(int i=1; i<=n; i++){
		for(int j=min(i, k); j>0; j--){
			dp[j] += dp[j-1];
		}
		Print(dp);
	}
	return dp[k];
}

int main(int argc, char const *argv[]) {
	int n, k;
	cin>>n>>k;
	cout<<binomial(n, k)<<endl;
	return 0;
}