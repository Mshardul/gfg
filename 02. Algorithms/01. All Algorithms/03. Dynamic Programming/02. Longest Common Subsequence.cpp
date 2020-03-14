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

int lcs(string s1, string s2){
	int n1 = s1.size();
	int n2 = s2.size();
	
	vector<vector<int> > dp;
	dp.resize(n1+1, vector<int> (n2+1));
		
	for(int i=1; i<=n1; i++){
		for(int j=1; j<=n2; j++){
			if(s1[i-1]==s2[j-1]){
				dp[i][j] = 1+dp[i-1][j-1];
			}else{
				dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
			}
		}
	}
	
	// Print2D(dp);
	return dp[n1][n2];
}

int main(int argc, char const *argv[]) {
	string s1, s2;
	cin>>s1>>s2;
	
	cout<<lcs(s1, s2)<<endl;
	return 0;
}