#include<iostream>
#include<vector>

using namespace std;

int fine(vector<int> car, vector<int> penalties, int n, int d){
	int eo = (d%2==0)?1:0;
	int ans = 0;
	for(int i=0; i<n; i++){
		if(car[i]%2==eo)
			ans += penalties[i];
	}
	return ans;
}

int main(int argc, char const *argv[]) {
	int t;
	cin>>t;
	while(t-->0){
		int n, d;
		cin>>n>>d;
		vector<int> car(n);
		for(int i=0; i<n; i++)
			cin>>car[i];
		vector<int> penalties(n);
		for(int i=0; i<n; i++)
			cin>>penalties[i];
		cout<<fine(car, penalties, n, d)<<endl;
	}
	return 0;
}