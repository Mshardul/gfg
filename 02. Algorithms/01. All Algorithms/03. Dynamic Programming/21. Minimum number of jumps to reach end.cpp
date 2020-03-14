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
/*
int minJump(vector<int> vec, int n){
	vector<int> dp(n);
	dp[0] = 0;
	for(int i=1; i<n; i++){
		int ans = n;
		for(int j=i-1; j>=0; j--){
			if(vec[j]+j>=i && dp[j]<ans)
				ans = dp[j];
		}
		dp[i] = ans+1;
	}
	Print(dp);
	return dp[n-1];
}
*/
int minJump(vector<int> vec, int n){ //should work
	vector<int> dp(n);
	dp[0] = 0;
	int mxStep = vec[0];
	int step = 0;
	int i=0; 
	while(i<n){
		int m = mxStep;
		int mx = 0;
		while(m-->0){
			mx = max(mx, vec[i+m]);
		}
		if(mx==0)
			return -1;
		i += mxStep;
		mxStep = mx;
		step++;
		cout<<i<<" "<<mxStep<<endl;
	}
	return step;
}

int main(int argc, char const *argv[]) {
	int n;
	cin>>n;
	vector<int> vec(n);
	for(int i=0; i<n; i++)
		cin>>vec[i];
	cout<<minJump(vec, n)<<endl;
	return 0;
}