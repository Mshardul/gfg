//didnt understand the problem

#include<iostream>
#include<vector>

using namespace std;

int main(int argc, char const *argv[]) {
	int n;
	cin>>n;
	vector<int> vec(n);
	for(int i=0; i<n; i++)
		cin>>vec[i];
	cout<<pyramidHeight(vec, n)<<endl;
	return 0;
}