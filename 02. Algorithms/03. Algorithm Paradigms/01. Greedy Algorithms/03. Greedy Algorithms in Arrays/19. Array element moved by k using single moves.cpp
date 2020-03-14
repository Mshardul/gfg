#include<iostream>
#include<vector>

using namespace std;

int winner(vector<int> vec, int n){ //cant think of linear
	for(int i=0; i<n; i++)
		vec.push_back(vec[i]);
	for(int i=0; i<n; i++)
		
}

int main(int argc, char const *argv[]) {
	int n;
	cin>>n;
	vector<int> q;
	for(int i=0; i<n; i++)
		cin>>vec[i];
	cout<<winner(q, n)<<endl;
	return 0;
}