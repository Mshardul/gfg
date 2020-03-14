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
	cout<<"-----------\n";
}
int lcs(string x, int n, string y, int m){
	vector<vector<int> > vec;
	vec.resize(n+1, vector<int>(m+1));
	
	for(int i=0; i<n; i++)
		vec[i][0] = 0;
	for(int i=0; i<m; i++)
		vec[0][i] = 0;
	
	// bottom up approach
	for(int i=0; i<n; i++){
		for(int j=0; j<m; j++){
			if(x[i]==y[j]){
				vec[i+1][j+1] = 1+vec[i][j];
			}else{
				vec[i+1][j+1] = max(vec[i+1][j], vec[i][j+1]);
			}
		}
		// Print2D(vec);
	}
	return vec[n][m];
}

int main(int argc, char const *argv[]) {
	int t;
	cin>>t;
	while(t-->0){
		int n, m;
		cin>>n>>m;
		string x, y;
		cin>>x>>y;
		cout<<lcs(x, n, y, m)<<endl;
	}
	return 0;
}