#include<iostream>
#include<vector>

using namespace std;

void Print(vector<int> dp){
	vector<int>::iterator iter = dp.begin();
	while(iter!=dp.end()){
		cout<<*iter<<" ";
		iter++;
	}
	cout<<endl;
}

int lis(vector<int> vec, int n){
	vector<int> dp(n);
	int ret = 1;
	dp[0] = 1;
	for(int i=1; i<n; i++){
		int ans = 1;
		for(int j=i-1; j>-1; j--){
			if(vec[j]<vec[i]){
				ans = max(ans, 1+dp[j]);
				ret = ans;
			}
		}
		dp[i] = ans;
	}
	// Print(dp);
	return ret;
}

int main(int argc, char const *argv[]) {
	int n;
	cin>>n;
	vector<int> vec(n);
	for(int i=0; i<n; i++)
		cin>>vec[i];
	
	cout<<lis(vec, n)<<endl;
	return 0;
}