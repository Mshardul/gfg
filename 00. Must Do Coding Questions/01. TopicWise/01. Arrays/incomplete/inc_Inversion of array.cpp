/* O(n^2) */

#include<iostream>
#include<vector>

using namespace std;

int main(int argc, char const *argv[]) {
	int t;
	cin>>t;
	while(t-->0){
		int n;
		cin>>n;
		vector<int> vec(n);
		for(int i=0; i<n; i++)
			cin>>vec[i];
		int ans = 0;
		for(int i=0; i<n; i++){
			for(int j=i+1; j<n; j++){
				if(vec[i]>vec[j])
					ans++;
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}