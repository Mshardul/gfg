#include<iostream>
#include<vector>
#include<unordered_map>

using namespace std;

//assuming no 0s, and unique

vector<int> GetUniq(vector<int> vec, int n){
	unordered_map<int, bool> mp;
	vector<int> ret;
	for(int i=0; i<n; i++){
		if(mp.find(vec[i])==mp.end()){
			mp.insert(make_pair(vec[i], true));
			ret.push_back(vec[i]);
		}
	}
	return ret;
}

int coin(vector<int> vec, int ind, int n, int curr, int k){ //tle
	if(curr==k)
		return 1;
	if(curr>k || ind>=n)
		return 0;
	int ret = 0;
	int excl = coin(vec, ind+1, n, curr, k);
	cout<<ind<<" -> e "<<excl<<endl;
	while(curr+vec[ind]<=k){
		int incl = coin(vec, ind+1, n, curr+vec[ind], k);
		cout<<ind<<" -> i "<<incl<<endl;
		ret += incl;
		curr += vec[ind];
	}
	return ret+excl;
}

int count( vector<int> S, int n, int k ) { //copied
	int i, j, x, y;
	int table[k+1][n]; //k using first n elements;
	for(i=0; i<n; i++)
		table[0][i] = 1;
	for(i=1; i<k+1; i++) {
		for(j=0; j<n; j++){
			x = (i-S[j]>=0) ? table[i-S[j]][j] : 0;
			y = (j>=1) ? table[i][j-1] : 0;
			table[i][j] = x+y;
		}
	}
  return table[k][n-1];
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
		int k;
		cin>>k;
		vector<int> uniq = GetUniq(vec, n);
		// cout<<coin(uniq, 0, n, 0, k)<<endl;
		cout<<count(uniq, n, k)<<endl;
	}
	return 0;
}