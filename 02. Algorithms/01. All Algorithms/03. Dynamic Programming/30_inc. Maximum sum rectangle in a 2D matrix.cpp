//should be done using kadane's

#include<iostream>
#include<vector>

using namespace std;

int maxSumRectangle(vector<vector<int> > vec, int n, int m){
	vector<vector<int> > dp;
	dp.resize(n, vector<int>(m));
	
	int currSum = 0;
	
}

int main(int argc, char const *argv[]) {
	int n, m;
	cin>>n>>m;
	
	vector<vector<int> > vec;
	vec.resize(n, vector<int>(m));
	
	cout<<maxSumRectangle(vec, n, m)<<endl;
	return 0;
}