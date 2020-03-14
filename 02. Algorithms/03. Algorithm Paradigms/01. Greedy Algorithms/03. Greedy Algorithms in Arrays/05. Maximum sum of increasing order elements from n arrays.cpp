#include<iostream>
#include<vector>

using namespace std;

int maxSum(vector<vector<int> > vec, int n, int m){ //seems right
	int sum = 0;
	int prev = INT_MAX;
	for(int i=n-1; i>-1; i--){
		int mx = INT_MIN;
		for(int j=0; j<m; j++){
			if(vec[i][j]<prev && vec[i][j]>mx)
				mx = vec[i][j];
		}
		if(mx==INT_MIN)
			return 0;
		sum += mx;
		prev = mx;
	}
	return sum;
}

int main(int argc, char const *argv[]) {
	int t;
	cin>>t;
	while(t-->0){
		int n, m;
		cin>>n>>m;
		vector<vector<int> > vec;
		vec.resize(n, vector<int>(m));
		for(int i=0; i<n; i++){
			for(int j=0; j<m; j++)
				cin>>vec[i][j];
		}
		cout<<maxSum(vec, n, m)<<endl;
	}
	return 0;
}