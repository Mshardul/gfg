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

int lps(string s){ //something is wrong
	int n = s.size();
	vector<vector<int> > dp;
	dp.resize(n+1, vector<int>(n));

	int ret = 1;
	for(int i=n-1; i>-1; i--){
		for(int j=0; j<n-i; j++){
			if(s[i]==s[j]){
				if(i==j)
					dp[i][j] = 1;
				else if(i==j-1)
					dp[i][j] = 2;
				else
					dp[i][j] = 2+dp[i+1][j-1];
				ret = max(ret, dp[i][j]);
			}
		}
	}
	Print2D(dp);
	return ret;
}

int main(int argc, char const *argv[]) {
	string s;
	cin>>s;
	
	cout<<lps(s)<<endl;
	return 0;
}