#include<iostream>
#include<vector>

using namespace std;

void Print(vector<int> vec){
	vector<int>::iterator iter = vec.begin();
	while(iter!=vec.end()){
		cout<<(*iter)<<" ";
		iter++;
	}
	cout<<endl;
}

int minJumps(vector<int> vec, int n){
	vector<int> dp(n);
	dp[n-1] = 0;
	
	for(int i=n-2; i>-1; i--){
		int j = vec[i];
		if(j==0){
			dp[i] = -1;
		}else if(i+j>=n-1){
			dp[i] = 1;
		}else{
			int ans = INT_MAX;
			while(j>0){
				int nextVal = dp[i+j];
				if(nextVal!=-1 && 1+nextVal<ans)
					ans = 1+nextVal;
				j--;
			}
			if(ans==INT_MAX)
				dp[i] = -1;
			else
				dp[i] = ans;
		}
		Print(dp);
	}
	return dp[0];
}

int main(int argc, char const *argv[]) {
	int t;
	cin>>t;
	while(t-->0){
		int n;
		cin>>n;
		vector<int> vec(n);
		for(int i=0; i<n; i++)
			cin>>vec[i];
		cout<<minJumps(vec, n)<<endl;
	}
	return 0;
}