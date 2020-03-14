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

int msis(vector<int> vec, int n){
	vector<int> dp(n);
	int ret = INT_MIN;
	
	for(int i=0; i<n; i++){
		int ans = 0;
		for(int j=0; j<i; j++){
			if(vec[j]<vec[i] && dp[j]>ans)
				ans = dp[j];
		}
		dp[i] = vec[i]+ans;
		ret = max(ret, dp[i]);
	}
	Print(dp);
	return ret;
}

int main(int argc, char const *argv[]) {
	int n;
	cin>>n;
	vector<int> vec(n);
	for(int i=0; i<n; i++)
		cin>>vec[i];
	
	cout<<msis(vec, n)<<endl;
	return 0;
}