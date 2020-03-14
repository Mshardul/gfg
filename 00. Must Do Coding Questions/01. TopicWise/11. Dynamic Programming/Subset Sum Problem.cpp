#include<iostream>
#include<vector>

using namespace std;

bool subsetSum(vector<int> vec, int n, int sum, int ind, int currSum){ //exponential
	if(2*currSum == sum)
		return true;
	if(2*currSum>sum || ind>=n)
		return false;
	int excl = subsetSum(vec, n, sum, ind+1, currSum);
	int incl = subsetSum(vec, n, sum, ind+1, currSum+vec[ind]);
	return (excl||incl);
}

void Print2D(vector<vector<bool> > vec){
	int n = vec.size();
	for(int i=0; i<n; i++){
		int m = vec[i].size();
		for(int j=0; j<m; j++)
			cout<<vec[i][j]<<" ";
		cout<<endl;
	}
	cout<<"-------------\n";
}

void Print(vector<bool> vec){
	vector<bool>::iterator iter = vec.begin();
	while(iter!=vec.end()){
		cout<<(*iter)<<" ";
		iter++;
	}
	cout<<endl;
}
bool subsetSum(vector<int> vec, int n){ //tle - n*s not working. :(
	int sum = 0;
	
	for(int i=0; i<n; i++)
		sum += vec[i];
	
	if(sum%2==1)
		return false;
		
	sum /= 2;
	vector<bool> prev(sum+1);
	
	for(int i=0; i<n; i++){
		if(vec[i]>sum)
			break;
		prev[vec[i]] = true;
	}
	
	for(int i=1; i<n; i++){ // no idea why it is giving tle
		vector<bool> curr(sum+1);
		for(int j=1; j<=sum; j++){
			curr[j] = prev[j]; //excluded
			if(j>vec[i-1])
				curr[j] = curr[j] || prev[j-vec[i-1]]; //include
		}
		prev = curr;
	}
	return prev[sum];
}

bool canPartition(vector<int>& nums) { //copied
	int sum = 0;
	for(int x: nums) sum += x;
	if(sum % 2) return false;
	vector<vector<bool> >dp(nums.size(), vector<bool>(sum / 2 + 1, false));
	dp[0][0] = true;
	for(int i = 1; i < nums.size(); i++){
		for(int j = 0; j < sum / 2 + 1; j++){
			dp[i][j] = dp[i - 1][j] || ((j >= nums[i]) ? dp[i - 1][j - nums[i]] : 0);
		}
	}
	Print2D(dp);
	return dp[nums.size() - 1][sum / 2];
}
		
int main(int argc, char const *argv[]) {
	int t;
	cin>>t;
	while(t-->0){
		int n;
		cin>>n;
		vector<int> vec(n);
		int sum;
		for(int i=0; i<n; i++){
			cin>>vec[i];
			sum += vec[i];
		}
		// if(subsetSum(vec, n, sum, 0, 0))
		// if(subsetSum(vec, n))
		if(canPartition(vec))
			cout<<"YES";
		else
			cout<<"NO";
		cout<<endl;
	}
	return 0;
}