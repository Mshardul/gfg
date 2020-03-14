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

int knapsack(int n, vector<int> wt, vector<int> val, int w){
	vector<vector<int> > dp;
	dp.resize(n+1, vector<int>(w+1));
	
	int ans = 0;
	int include, exclude;
	for(int i=1; i<=n; i++){
		for(int j=1; j<=w; j++){
			if(j>=wt[i-1])
				include = val[i-1] + dp[i-1][j-wt[i-1]];
			else
				include = val[i-1];
			
			exclude = dp[i-1][j];
			dp[i][j] = max(include, exclude);
			ans = max(ans, dp[i][j]);
		}
	}
	Print2D(dp);
	return ans;
}

int main(int argc, char const *argv[]) {
	int n;
	cin>>n;
	
	vector<int> wt(n);
	vector<int> val(n);
	
	for(int i=0; i<n; i++)
		cin>>wt[i];
	for(int i=0; i<n; i++)
		cin>>val[i];
	
	int w;
	cin>>w;
	
	cout<<knapsack(n, wt, val, w)<<endl;
	return 0;
}