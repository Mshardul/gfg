#include<iostream>
#include<vector>

using namespace std;

bool partitionBacktrack(vector<int> vec, int ind, int n, int sum, int currSum){
	if((2*currSum)>sum || ind>=n)
		return false;
	if(2*currSum==sum)
		return true;
	
	bool excl = partitionBacktrack(vec, ind+1, n, sum, currSum);
	bool incl = partitionBacktrack(vec, ind+1, n, sum, currSum+vec[ind]);
	
	return (incl||excl);
}

void Print(vector<bool> vec){
	vector<bool>::iterator iter = vec.begin();
	while(iter!=vec.end()){
		cout<<*iter<<" ";
		iter++;
	}
	cout<<endl;
}

void Print2D(vector<vector<bool> > vec){
	int n = vec.size();
	for(int i=0; i<n; i++){
		int m = vec[i].size();
		for(int j=0; j<m; j++)
			cout<<vec[i][j]<<" ";
		cout<<endl;
	}
	cout<<"--------------\n";
}

bool partitionDP(vector<int> vec, int n, int sum){
	vector<vector<bool> > dp;
	dp.resize(n+1, vector<bool> (sum+1));
	
	for(int i=0; i<=n; i++)
		dp[i][0] = true;
	for(int i=1; i<=sum; i++)
		dp[0][i] = false;
		
	for(int i=1; i<=n; i++){
		for(int j=1; j<=sum; j++){
			if(j>=vec[i-1])
				dp[i][j] = dp[i-1][j] || dp[i-1][j-vec[i-1]];
			else
				dp[i][j] = dp[i-1][j];
		}
	}
	Print2D(dp);
	
	vector<bool> dp2(sum+1, false);
	dp2[0] = true;
	for(int i=n; i>0; i--){
		for(int j=sum-1; j>0; j--){
			if(j>=vec[i-1])
				dp2[j] = dp2[j]||dp2[j-vec[i-1]];
		}
		Print(dp2);
	}
	
	return dp2[sum];
}

int main(int argc, char const *argv[]) {
	int n;
	cin>>n;
	
	vector<int> vec(n);
	int sum = 0;
	for(int i=0; i<n; i++){
		cin>>vec[i];
		sum+=vec[i];
	}
	
	if(sum%2==1){
		cout<<"0";
	}else{
		// cout<<partitionBacktrack(vec, 0, n, sum, 0)<<endl;
		cout<<partitionDP(vec, n, sum/2);
		cout<<findPartiion (vec, n);
	}
	cout<<endl;
	return 0;
}