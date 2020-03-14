#include<iostream>
#include<vector>

using namespace std;

/*
bool subsetSum(vector<int> vec, int n, int sum){ //(n^2, n)
	vector<int> cSum(n+1);
	for(int i=1; i<=n; i++)
		cSum[i] = cSum[i-1]+vec[i];
	for(int i=0; i<=n; i++){
		for(int j=i+1; j<=n; j++){
			if(cSum[j]-cSum[i]==sum)
				return 1;
		}
	}
	return 0;
}
*/

void Print(vector<vector<bool> > dp){
	int n = dp.size();
	for(int i=0; i<n; i++){
		int m = dp[i].size();
		for(int j=0; j<m; j++)
			cout<<dp[i][j]<<" ";
		cout<<endl;
	}
}

bool subsetSum(vector<int> vec, int n, int sum){ //(n*sum, n*sum)
	vector<vector<bool> > dp;
	dp.resize(n, vector<bool> (sum+1));
	
	for(int i=0; i<n; i++)
		dp[i][0] = true;
	
	for(int i=0; i<=sum; i++){
		if(vec[0]==i)
			dp[0][i] = true;
	}

	for(int i=1; i<n; i++){
		for(int j=1; j<=sum; j++){
			dp[i][j] = dp[i-1][j];
			if(j>vec[i])
				dp[i][j] = dp[i][j] || dp[i-1][j-vec[i]];
		}
	}
	
	Print(dp);
	return dp[n-1][sum];
}

int main(int argc, char const *argv[]) {
	int n;
	cin>>n;
	
	vector<int> vec(n);
	for(int i=0; i<n; i++)
		cin>>vec[i];
	
	int k;
	cin>>k;
	
	cout<<subsetSum(vec, n, k)<<endl;
	return 0;
}