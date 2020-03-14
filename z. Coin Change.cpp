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

int ways(vector<int> vec, int k){
	int n = vec.size();
	if(n==0)
		return 0;
	vector<vector<int> > dp;
	dp.resize(n, vector<int>(k+1));
	
	for(int i=1; i<=k; i++)
		if(i%vec[0]==0)
			dp[0][i] = 1;
	for(int i=0; i<n; i++)
		dp[i][0] = 1;
			
	for(int i=1; i<n; i++){
		for(int j=1; j<=k; j++){
			dp[i][j] = dp[i-1][j];
			if(j>=vec[i])
				dp[i][j] = dp[i][j] + dp[i][j-vec[i]];
		}
	}
	Print2D(dp);
	return dp[n-1][k];
}

int main(int argc, char const *argv[]) {
    int t;
    cin>>t;
    while(t-->0){
    	int n, k;
	    cin>>n;
	    vector<int> vec(n);
	    for(int i=0; i<n; i++)
		    cin>>vec[i];
	    cin>>k;
	    cout<<ways(vec, k)<<endl;
    }
	return 0;
}