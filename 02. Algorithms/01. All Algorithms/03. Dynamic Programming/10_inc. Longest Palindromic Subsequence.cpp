#include<iostream>
#include<vector>

using namespace std;

int lcs(string s1, string s2){
	int n = s1.size();
	vector<vector<int> > dp;
	dp.resize(n+1, vector<int>(n+1));
	
	for(int i=1; i<=n; i++){
		for(int j=1; j<=n; j++){
			if(s1[i-1]==s2[j-1]){
				dp[i][j] = 1+dp[i-1][j-1];
			}else{
				dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
			}
		}
	}
	
	return dp[n][n];
}

int lps(string s){ //method1 - lcs(s, reverse(s))
	string s2 = "";
	for(char ch:s)
		s2 = string(1, ch) + s2;
	return lcs(s, s2);
}

int lps(string s){
	int n = s.size();
	for(int i=1; i<n; i++){
		for(int j=1; j<n; j++){
			if(i==j)
				dp[i][j] = 1;
			else{
				if(s[i]==s[j])
					dp[i]
			}
		}
	}
}

int lps(char *str) { //copied - approach similar to matrix multiplication
	int n = strlen(str);
	int i, j, cl;
	int L[n][n];

	for (i = 0; i < n; i++) 
		L[i][i] = 1;
	for (cl=2; cl<=n; cl++){
		for (i=0; i<n-cl+1; i++) {
			j = i+cl-1;
			if (str[i] == str[j] && cl == 2)
				L[i][j] = 2;
			else if (str[i] == str[j])
				L[i][j] = L[i+1][j-1] + 2;
			else
				L[i][j] = max(L[i][j-1], L[i+1][j]);
		}
	}
	
	return L[0][n-1];
} 

int main(int argc, char const *argv[]) {
	string s;
	cin>>s;
	cout<<lps(s)<<endl;
	return 0;
}