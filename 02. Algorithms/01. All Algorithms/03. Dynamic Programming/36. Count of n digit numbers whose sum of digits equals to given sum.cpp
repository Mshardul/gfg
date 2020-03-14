#include<iostream>
#include<vector>

using namespace std;

Print2D(vector<vector<int> > vec){
	int n = vec.size();
	for(int i=0; i<n; i++){
		int m = vec[i].size();
		for(int j=0; j<m; j++)
			cout<<vec[i][j]<<" ";
		cout<<endl;
	}
}

void func(int n, vector<int> nums, vector<vector<int> > ans){
	for(int i=0; i<10; i++)
		
}

int main(int argc, char const *argv[]) {
	int n;
	cin>>n;
	
	int ans = 0;
	for(int i=0; i<n; i++)
		ans += 
	
	vector<vector<int> > ans;
	func(n, nums, ans, 0);
	
	Print2D(ans);
	return 0;
}