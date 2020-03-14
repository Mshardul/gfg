#include<iostream>
#include<vector>

using namespace std;

long long int sum(vector<int> vec, int n){
	sort(vec.begin(), vec.end());
	long long int ans = 0;
	for(int i=0; i<n; i++)
		ans += (i*vec[i]);
	return ans;
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
		cout<<sum(vec, n)<<endl;
	}
	return 0;
}