#include<iostream>
#include<vector>

using namespace std;

int maxAbsDiff(vector<int> vec, int n){
	sort(vec.begin(), vec.end());
	vector<int> ans(n);
	int l=0, r=n-1, ind=0;
	while(l<r){
		ans[ind++] = vec[l++];
		ans[ind++] = vec[r--];
	}
	if(n%2==1)
		ans[ind] = vec[l];
	int sum = 0;
	for(int i=1; i<n; i++){
		sum += abs(ans[i]-ans[i-1]);
	}
	sum += abs(ans[0]-ans[n-1]);
	return sum;
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
		cout<<maxAbsDiff(vec, n)<<endl;
	}
	return 0;
}