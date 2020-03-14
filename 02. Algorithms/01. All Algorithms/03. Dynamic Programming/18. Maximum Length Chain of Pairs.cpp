//similar to LIS

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

int chain(vector<pair<int, int> > vec, int n){
	vector<int> dp(n);
	int ret = 1;
	for(int i=0; i<n; i++){
		int ans = 0;
		for(int j=i-1; j>-1; j--){
			if(vec[i].first>vec[j].second && dp[j]>ans)
				ans = dp[j];
		}
		dp[i] = ans+1;
		if(dp[i]>ret)
			ret = dp[i];
	}
	Print(dp);
	return ret;
}

int main(int argc, char const *argv[]) {
	int n;
	cin>>n;
	
	vector<pair<int, int> > vec(n);
	int a, b;
	for(int i=0; i<n; i++){
		cin>>a>>b;
		vec[i] = make_pair(a, b);
	}
	
	cout<<chain(vec, n)<<endl;
	return 0;
}