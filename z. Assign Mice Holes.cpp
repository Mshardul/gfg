#include<iostream>
#include<vector>

using namespace std;

int Assign(vector<int> mice, vector<int> holes, int n){
	sort(mice.begin(), mice.end());
	sort(holes.begin(), holes.end());
	int ans = 0;
	for(int i=0; i<n; i++){
		cout<<i<<" "<<mice[i]<<" "<<holes[i]<<" "<<abs(mice[i]-holes[i])<<" "<<ans<<endl;
		ans = max(ans, abs(mice[i]-holes[i]));
	}
	return ans;
}

int main(int argc, char const *argv[]) {
	int t;
	cin>>t;
	while(t-->0){
		int n;
		cin>>n;
		vector<int> mice(n);
		vector<int> holes(n);
		for(int i=0; i<n; i++)
			cin>>mice[i];
		for(int i=0; i<n; i++)
			cin>>holes[i];
		cout<<Assign(mice, holes, n)<<endl;
	}
	return 0;
}