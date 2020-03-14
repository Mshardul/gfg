/* O(n^2) */

#include<iostream>
#include<vector>
#include<unordered_set>

using namespace std;

int main(int argc, char const *argv[]) {
	int t;
	cin>>t;
	while(t-->0){
		int n, temp;
		cin>>n;
		vector<int> vec(n);
		unordered_set<int> st;
		for(int i=0; i<n; i++){
			cin>>temp;
			vec[i] = temp;
			st.insert(temp);
		}
		int ans = 0;
		for(int i=0; i<n; i++){
			for(int j=i+1; j<n; j++){
				if(st.find(vec[i]+vec[j]) != st.end())
					ans++;
			}
		}
		if(ans==0)
			ans = -1;
		cout<<ans<<endl;
	}
	return 0;
}