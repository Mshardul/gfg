#include<iostream>
#include<vector>
using namespace std;

void Print(vector<int> vec){
	int n = vec.size();
	for(int i=0; i<n; i++)
		cout<<i<<"->"<<vec[i]<<endl;
}

int GetMinOp(int n){
	vector<int> vec(n+1);
	if(n<3)
		return n;
	vec[0] = 0;
	vec[1] = 1;
	vec[2] = 2;
	for(int i=3; i<=n; i++){
		int half = i/2;
		int prev = 1+vec[i-1];
		if(2*half==i)
			vec[i] = min((1+vec[half]), prev);
		else
			vec[i] = min((2+vec[half]), prev);
	}
	return vec[n];
}

int main(){
	int t;
	cin>>t;
	while(t-->0){
		int n;
		cin>>n;
		cout<<GetMinOp(n)<<endl;
	}
	return 0;
}