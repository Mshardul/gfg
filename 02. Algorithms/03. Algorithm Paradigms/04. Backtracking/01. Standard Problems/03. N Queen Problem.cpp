#include<iostream>
#include<vector>

using namespace std;

bool rowSafe(vector<vector<bool> > vec, int n, int i, int j){
	for(int x=0; x<n; x++)
		if(x!=j && vec[i][x]==true)
			return false;
	return true;
}

bool colSafe(vector<vector<bool> > vec, int n, int i, int j){
	for(int x=0; x<n; x++)
		if(x!=i && vec[x][j]==true)
			return false;
	return true;
}

bool diagSafe(vector<vector<bool> > vec, int n, int row, int col){
	for(int i=1; i<=min(row, col); i++)
		if(vec[row-i][col-i]==true)
			return false;
	for(int i=1; i<n-max(row, col); i++)
		if(vec[row+i][col+i]==true)
			return false;
	for(int i=1; i<min(row, n-col); i++)
		if(vec[row-i][col+1]==true)
			return false;
	for(int i=1; i<min(n-row, col); i++)
		if(vec[row+i][col-i]==true)
			return false;
	return true;
}

bool isSafe(vector<vector<bool> > vec, int n, int i, int j){
	if(rowSafe(vec, n, i, j) && colSafe(vec, n, i, j) && diagSafe(vec, n, i, j))
		return true;
	return false;
}

void Print2D(vector<vector<bool> > vec){
	int n = vec.size();
	cout<<"----------\n";
	for(int i=0; i<n; i++){
		for(int j=0; j<n; j++)
			cout<<vec[i][j]<<" ";
		cout<<endl;
	}
	cout<<"----------\n";
}

bool Backtrack(vector<vector<bool> > &vec, int n, int row){
	if(row==n){
		Print2D(vec);
		return true;
	}
	for(int i=0; i<n; i++){
		if(isSafe(vec, n, row, i)){
			vec[row][i] = true;
			Backtrack(vec, n, row+1);
			vec[row][i] = false;
		}
	}
	return false;
}

int main(int argc, char const *argv[]) {
	int n;
	cin>>n;
	vector<vector<bool> > vec;
	vec.resize(n, vector<bool>(n, false));
	Backtrack(vec, n, 0);
	return 0;
}