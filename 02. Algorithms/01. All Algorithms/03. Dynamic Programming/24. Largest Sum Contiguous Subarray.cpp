#include<iostream>
#include<vector>

using namespace std;

/*
int lscs(vector<int> vec, int n){ //n^2 solution
	vector<int> cSum(n);
	cSum[0] = vec[0];
	for(int i=1; i<n; i++)
		cSum[i] = vec[i]+cSum[i-1];
	
	int ans = 0;
	for(int i=0; i<n; i++){
		for(int j=i+1; j<n; j++)
			ans = max(ans, abs(cSum[i]-cSum[j]));
	}
	
	return ans;	
}
*/

int lscs(vector<int> vec, int n){
	int currSum = vec[0];
	int mx = currSum;
	for(int i=1; i<n; i++){
		if(currSum+vec[i]<0)
			currSum = 0;
		else
			currSum += vec[i];
		if(currSum>mx)
			mx = currSum;
		cout<<i<<" "<<currSum<<" "<<mx<<endl;
	}
	return mx;
}

int main(int argc, char const *argv[]) {
	int n;
	cin>>n;
	vector<int> vec(n);
	for(int i=0; i<n; i++)
		cin>>vec[i];
	cout<<lscs(vec, n)<<endl;
	return 0;
}