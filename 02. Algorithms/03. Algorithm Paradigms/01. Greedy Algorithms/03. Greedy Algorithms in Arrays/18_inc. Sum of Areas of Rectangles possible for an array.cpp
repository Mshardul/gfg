#include<iostream>
#include<vector>

using namespace std;

int sum(vector<int> vec, int n){
	sort(vec.begin(), vec.end());
	vector<int> ret;
	
	for(int i=0; i<n; i++){
		
	}
}

int main(int argc, char const *argv[]) {
	int n;
	cin>>n;
	vector<int> vec(n);
	for(int i=0; i<n; i++)
		cin>>vec[i];
	cout<<sum(vec, n)<<endl;
	return 0;
}