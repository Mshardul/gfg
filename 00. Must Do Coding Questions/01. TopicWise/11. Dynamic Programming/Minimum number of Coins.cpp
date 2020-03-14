#include<iostream>
#include<vector>
// #include<bits/stdc++.h>
using namespace std;

void Print(vector<int> vec){
	int n = vec.size();
	for(int i=0; i<n; i++)
		cout<<vec[i]<<" ";
	cout<<endl;
}

vector<int> GetCoins(vector<int> dp, int n, int vec[]){
	vector<int> ans;
	int i = n;
	int k = 11; //no of coins
	int row = n+1;
	int del;
	while(i>0 && k>=0){
		if(i>=vec[k] && dp[i]==1+dp[i-vec[k]]){
			ans.push_back(vec[k]);
			i -= vec[k];
		}else{
			k--;
		}
	}
	while(i>0){
		ans.push_back(1);
		i--;
	}
	return ans;
}

vector<int> GetNoOfCoins(int n){
	int vec[11] = { 0, 1, 2, 5, 10, 20, 50, 100, 200, 500, 2000};
	int k = 11;
	vector<int> dp(n+1); //dp[n]
	for(int i=0; i<n+1; i++)
		dp[i] = i;
	
	for(int j=1; j<k; j++){ // 'i' amount using first 'j' coins
		for(int i=0; i<n+1; i++){
			if(i>=vec[j] && (1+dp[i-vec[j]])<dp[i])
				dp[i] = 1+dp[i-vec[j]];
		}
	}
	// Print(dp);
	return GetCoins(dp, n, vec);
}

int main(int argc, char const *argv[]) {
	int t;
	cin>>t;
	while(t-->0){
		int n;
		cin>>n;
		vector<int> ans = GetNoOfCoins(n);
		Print(ans);
	}
	return 0;
}