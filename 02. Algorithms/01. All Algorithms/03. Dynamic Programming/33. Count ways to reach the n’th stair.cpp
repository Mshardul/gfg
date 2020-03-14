#include<iostream>
#include<vector>

using namespace std;

int stair(int n){
	vector<int> vec(n);
	vec[0] = 1;
	vec[1] = 1;
	for(int i=2; i<n; i++){
		vec[i] = vec[i-1]+vec[i-2]; //just fibonacci
		cout<<i<<" "<<vec[i]<<endl;
	}
	return vec[n-1];
}

int main(int argc, char const *argv[]) {
	int n;
	cin>>n;
	
	cout<<stair(n)<<endl;
	return 0;
}