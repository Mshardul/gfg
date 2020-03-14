/*
dp[i] = max(ans, pr[j]+dp[i-1-j]);
j = {1,2,3...i-1}
*/

#include<iostream>
#include<vector>

using namespace std;

void Print(vector<int> vec){
	int n = vec.size();
	for(int i=0; i<n; i++)
		cout<<vec[i]<<" ";
	cout<<endl;
}

int cut(vector<int> pr, int n){
	vector<int> dp[n+1];
	dp[0] = 0;
	
	for(int i=1; i<=n; i++){
		int ans = INT_MIN;
		for(int j=0; j<i; j++)
			ans = max(ans, pr[j]+dp[i-1-j]);
		dp[i] = ans;
	}
	
	return dp[n];
}

int main(int argc, char const *argv[]) {
	int n;
	cin>>n;
	vector<int> pr(n);
	for(int i=0; i<n; i++)
		cin>>pr[i];
		
	cout<<cut(pr, n)<<endl;
	return 0;
}