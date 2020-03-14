#include<iostream>
#include<vector>

using namespace std;

int minOp(vector<int> vec, int n, int k){
	sort(vec.begin(), vec.end());
	int ans = (vec[0]>k)?vec[0]-k:k-vec[0];
	for(int i=1; i<n; i++){
		int temp = vec[i]%k;
		ans += min(temp, k-temp);
	}
	return ans;
}

int main(int argc, char const *argv[]) {
	int n, k;
	cin>>n>>k;
	vector<int> vec(n);
	for(int i=0; i<n; i++)
		cin>>vec[i];
	cout<<minOp(vec, n, k)<<endl;
	return 0;
}