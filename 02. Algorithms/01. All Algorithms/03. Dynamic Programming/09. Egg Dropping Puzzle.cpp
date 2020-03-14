/*
dp[i, j] = min(1+max(dp[i-1][x-1], dp[i][j-x]))
//x = {1,2,3...k}
*/

#include<iostream>
#include<vector>

using namespace std;

int EggDrop(int n, int k){
	vector<vector<int> > dp;
	dp.resize(n+1, vector<int> (k+1));
	
	for(int i=1; i<=n; i++){
		for(int j=1; j<=k; j++){
			if(i==1)
				dp[i][j] = j;
			else if(j==1)
				dp[i][j] = i;
			else{
				dp[i][j] = INT_MAX;
				for (x = 1; x <= j; x++) {
					res = 1 + max(dp[i-1][x-1], dp[i][j-x]);
					if (res < dp[i][j])
						dp[i][j] = res;
        }
			}
		}
	}
	return dp[n][k];
}

int main(int argc, char const *argv[]) {
	int n, k;
	cin>>n>>k;
	cout<<EggDrop(n, k)<<endl;
	return 0;
}