#include<iostream>
#include<vector>

using namespace std;

void Print(vector<int> vec){
	vector<int>::iterator iter = vec.begin();
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
}

bool Backtrack(vector<int> vec, int n, vector<int> temp, int ind, int currSum, int sum){
	if(ind>n || currSum>sum)
		return false;
	if(currSum==sum){
		Print(temp);
		return true;
	}
	// cout<<ind<<" "<<currSum<<endl;
	bool excl = Backtrack(vec, n, temp, ind+1, currSum, sum);
	if(excl)
		return true;
	temp.push_back(vec[ind]);
	currSum+=vec[ind];
	bool incl = Backtrack(vec, n, temp, ind+1, currSum, sum);
	if(incl)
		return true;
	return false;
}

void SubsetSum(vector<int> vec, int n, int sum){ //exponential time
	int ind = 0;
	int currSum = 0;
	vector<int> temp;
	if(Backtrack(vec, n, temp, ind, currSum, sum))
		cout<<"found";
	else
		cout<<"not found";
	cout<<endl;
}

/*
void BacktrackSubset(vector<int> vec, vector<vector<bool> > dp, int n, int sum){
	int currSum = sum;
	int row = n-1;
	while(currSum>0){
		if(row>0 && dp[row][currSum]==dp[row-1][currSum]){
			row--;
		}else{
			cout<<vec[row]<<" ";
			currSum -= vec[row];
		}
	}
	cout<<endl;
}

void SubsetSum(vector<int> vec, int n, int sum){ //dp
	vector<vector<bool> > dp;
	dp.resize(n, vector<bool>(sum+1, false));
	for(int i=0; i<n; i++)
		dp[i][0] = true;
	if(vec[0]<=sum)
		dp[0][vec[0]] = true;
	for(int i=1; i<n; i++){
		for(int j=1; j<=sum; j++){
			dp[i][j] = dp[i-1][j];
			if(dp[i][j]==false && j>=vec[i])
				dp[i][j] = dp[i][j] || dp[i-1][j-vec[i]];
		}
	}
	// Print2D(dp);
	if(dp[n-1][sum]){
		BacktrackSubset(vec, dp, n, sum);
	}else{
		cout<<"not found";
	}
	cout<<endl;
}
*/

int main(int argc, char const *argv[]) {
	int n, sum;
	cin>>n>>sum;
	vector<int> vec(n);
	for(int i=0; i<n; i++)
		cin>>vec[i];
	SubsetSum(vec, n, sum);
	return 0;
}