#include<iostream>
#include<vector>

using namespace std;

int beautify(vector<vector<int> > vec){
	int n = vec.size();
	if(n==0)
		return 0;
	vector<int> cummRow(n, 0);
	vector<int> cummCol(m, 0);
	
	for(int i=0; i<n; i++){
		for(int j=0; j<m; j++){
			cummRow[i] += vec[i][j];
			cummCol[j] += vec[i][j];
		}
	}
	
	int mxRow=INT_MIN;
	for(int i=0; i<n; i++)
		mxRow = max(mxRow, cummRow[i]);
	
	int mxCol=INT_MIN;
	for(int i=0; i<m; i++)
		mxCol = max(mxCol, cummCol[i]);
	
	int ans = 0;
	int i=0, j=0;
	while(i<n && j<m){
		int diff = min(mxRow-cummRow[i], mxCol-cummCol[j]);
		
		vec[i][j] += diff;
		cummRow[i] += diff;
		cummCol[j] += diff;
		
		ans += diff;
		
		if(diff == cummRow[i])
			i++
		if(diff == cummCol[j])
			j++;
	}
}
int main(int argc, char const *argv[]) {
	int n, m;
	cin>>n>>m;
	vector<vector<int> > vec;
	vec.resize(n, vector<int>(m));
	for(int i=0; i<n; i++){
		for(int j=0; j<m; j++)
			cin>>vec[i][j];
	}
	cout<<beautify(vec);
	return 0;
}