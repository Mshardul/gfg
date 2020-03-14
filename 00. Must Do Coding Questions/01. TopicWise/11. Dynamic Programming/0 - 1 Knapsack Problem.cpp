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

int knapsack(int ind, int n, int w, vector<int> wt, vector<int> vec, int currWt, int currVal){ //tle - exponential
	if(currWt>w)
		return -1;
	if(ind>=n)
		return currVal;
		
	int excl = knapsack(ind+1, n, w, wt, vec, currWt, currVal);
	int incl = knapsack(ind+1, n, w, wt, vec, currWt+wt[ind], currVal+vec[ind]);
	
	cout<<ind<<" "<<excl<<" "<<incl<<endl;
	int sum = max(excl, incl);
	return sum;
}

int knapsack(int n, int w, vector<int> wt, vector<int> vec){ //tle
	vector<vector<int> > dp;
	dp.resize(n+1, vector<int>(w+1));
	for(int i=1; i<=n; i++){
		for(int j=1; j<=w; j++){
			if(wt[i-1]<=j)
				dp[i][j] = max(vec[i-1]+dp[i-1][j-wt[i-1]], dp[i-1][j]);
			else
				dp[i][j] = dp[i-1][j];
		}
	}
	// Print2D(dp);
	return dp[n][w];
}

int main(int argc, char const *argv[]) {
	int t;
	cin>>t;
	while(t-->0){
		int n, w;
		cin>>n>>w;
		
		vector<int> vec(n);
		for(int i=0; i<n; i++)
			cin>>vec[i];

		vector<int> wt(n);
		for(int i=0; i<n; i++)
			cin>>wt[i];
			
		// cout<<knapsack(0, n, w, wt, vec, 0, 0)<<endl;
		cout<<knapsack(n, w, wt, vec)<<endl;
	}
	return 0;
}