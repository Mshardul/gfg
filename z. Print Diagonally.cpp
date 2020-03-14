#include<iostream>
#include<vector>

using namespace std;

void Print(vector<vector<int> > vec, int n){
	for(int i=0; i<n; i++){
		int m = vec[i].size();
		for(int j=0; j<m; j++)
			cout<<vec[i][j]<<" ";
		cout<<endl;
	}
}

vector<vector<int> > diagonally(vector<vector<int> > vec, int n){
	vector<vector<int> > ret(n+n-1);
	for(int i=0; i<n; i++){
		for(int j=0; j<n; j++)
			ret[i+j].push_back(vec[i][j]);
	}
	return ret;
}

int main(int argc, char const *argv[]) {
	int t;
	cin>>t;
	while(t-->0){
		int n;
		cin>>n;
		vector<vector<int> > vec;
		vec.resize(n, vector<int>(n));
		for(int i=0; i<n; i++)
			for(int j=0; j<n; j++)
				cin>>vec[i][j];
		vector<vector<int> > ret = diagonally(vec, n);
		Print(ret, n+n-1);
	}
	return 0;
}