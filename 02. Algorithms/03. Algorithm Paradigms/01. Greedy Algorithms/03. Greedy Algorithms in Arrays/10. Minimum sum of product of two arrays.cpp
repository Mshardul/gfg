#include<iostream>
#include<vector>

using namespace std;

int minSop(vector<int> vec1, vector<int> vec2, int n , int k){
	k *= 2; //can be increased or decreased by 2
	int sop = 0;
	for(int i=0; i<n; i++)
		sop += vec1[i]*vec2[i];
	int mn = INT_MIN;
	for(int i=0; i<n; i++)
		mn = max(mn, abs(k*vec2[i]));
	return (sop-mn);
}

int main(int argc, char const *argv[]) {
	int n, k;
	cin>>n>>k;
	vector<int> vec1(n);
	for(int i=0; i<n; i++)
		cin>>vec1[i];
	vector<int> vec2(n);
	for(int i=0; i<n; i++)
		cin>>vec2[i];
	cout<<minSop(vec1, vec2, n, k)<<endl;
	return 0;
}