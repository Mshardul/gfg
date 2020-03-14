#include<iostream>
#include<vector>

using namespace std;

void Print2D(vector<vector<int> > vec){
	int n = vec.size();
	for(int i=0; i<n; i++){
		int m = vec[i].size();
		for(int j=0; j<m; j++)
			cout<<vec[i][j]<<" ";
		cout<<endl;
	}
}

/*
void RatInMaze(vector<vector<int> > vec, int n, int m){ //using dp
	vector<vector<bool> > dp;
	dp.resize(n, vector<bool>(m, false));
	for(int i=0; i<n; i++)
		dp[i][0] = vec[i][0];
	for(int j=0; j<m; j++)
		dp[0][j] = vec[0][j];
	for(int i=1; i<n; i++){
		for(int j=1; j<m; j++){
			if(vec[i][j]==1)
				dp[i][j] = dp[i-1][j]||dp[i][j-1];
		}
	}
	Print2D(dp);
	if(dp[n-1][m-1])
		cout<<"path exists\n";
	else
		cout<<"no path\n";
}
*/

bool Backtrack(vector<vector<int> > vec, int n, int m, int i, int j){
	if(i==n-1 && j==m-1)
		return vec[i][j];
	if(i>=n || j>=m || vec[i][j]==0)
		return false;
	cout<<i<<" "<<j<<endl;
	bool rt = Backtrack(vec, n, m, i, j+1);
	bool dn = Backtrack(vec, n, m, i+1, j);
	return rt||dn;
}

void RatInMaze(vector<vector<int> > vec, int n, int m){
	int h[] = {1, 0};
	int v[] = {0, 1};
	bool isPath = Backtrack(vec, n, m, 0, 0);
	Print2D(vec);
	if(isPath)
		cout<<"path exists\n";
	else
		cout<<"no path\n";
}

int main(int argc, char const *argv[]) {
	int n, m;
	cin>>n>>m;
	vector<vector<int> > vec;
	vec.resize(n, vector<int>(m));
	
	for(int i=0; i<n; i++)
		for(int j=0; j<m; j++)
			cin>>vec[i][j];
			
	RatInMaze(vec, n, m);
	return 0;
}