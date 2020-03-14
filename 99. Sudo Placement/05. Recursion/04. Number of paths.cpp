#include<iostream>
#include<vector>

using namespace std;

int RecurseWOdp(int x, int y){ //without dp
	if(x==0 || y==0)
		return 1;
	return RecurseWOdp(x-1, y) + RecurseWOdp(x, y-1);
}

int RecurseWdp(int x, int y, vector<vector<int> > &dp){
	if(dp[x][y]!=0)
		return dp[x][y];
	if(x==0 || y==0){
		dp[x][y] = 1;
		return 1;
	}
	int l = RecurseWdp(x-1, y, dp);
	int r = RecurseWdp(x, y-1, dp);
	dp[x][y] = l+r;
	return dp[x][y];
}
void Paths(int n, int m){
	// cout<<RecurseWOdp(n-1, m-1)<<endl;
	vector<vector<int> > dp(n, vector<int>(m));
	cout<<RecurseWdp(n-1, m-1, dp)<<endl;
}

int main(int argc, char const *argv[]) {
	int t;
	cin>>t;
	while(t-->0){
		int n, m;
		cin>>n>>m;
		Paths(n, m);
	}
	return 0;
}