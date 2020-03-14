#include<iostream>
#include<vector>
#include<climits>
#include<algorithm>

using namespace std;

//can be done using hashing, that ll take n log(k)
int distribute(vector<int> vec, int k){ //tle
	sort(vec.begin(), vec.end());
	int n = vec.size();
	int ans = INT_MAX;
	int l = 0;
	int r = k-1;
	while(r<n){
		ans = min(ans, vec[r]-vec[l]);
		r++;
		l++;
	}
	return ans;
}

int main(int argc, char const *argv[]) {
	int t;
	cin>>t;
	while(t-->0){
		int n, k;
		cin>>n;
		vector<int> vec(n);
		for(int i=0; i<n; i++)
			cin>>vec[i];
		cin>>k;
		cout<<distribute(vec, k)<<endl;
	}
	return 0;
}