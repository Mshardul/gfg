#include<iostream>
#include<vector>

using namespace std;

int dist(string s1, int n1, string s2, int n2){
	vector<vector<int> > dp;
	dp.resize(n1+1, vector<int> (n2+1));
	
	for(int i=0; i<=n1; i++)
		dp[i][0] = i;
	for(int i=0; i<=n2; i++)
		dp[0][i] = i;
		
	for(int i=1; i<=n1; i++){
		for(int j=1; j<=n2; j++){
			if(s1[i-1]==s2[i-1])
				dp[i][j] = dp[i-1][j-1];
			else
				dp[i][j] = 1+min(dp[i-1][j-1], min(dp[i-1][j], dp[i][j-1]));
		}
	}
	return dp[n1-1][n2-1];
}

int main(int argc, char const *argv[]) {
	string s1, s2;
	cin>>s1>>s2;
	
	int n1 = s1.size();
	int n2 = s2.size();
	
	cout<<dist(s1, n1, s2, n2)<<endl;
	return 0;
}