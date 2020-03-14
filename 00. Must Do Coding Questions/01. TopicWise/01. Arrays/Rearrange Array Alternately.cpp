/* O(n^2) */

#include<iostream>
#include<vector>
#include <algorithm>

using namespace std;

int main(int argc, char const *argv[]) {
	int t;
	cin>>t;
	while (t-->0) {
		int n;
		cin>>n;
		vector<int> vec(n);
		for(int i=0; i<n; i++)
			cin>>vec[i];
		sort(vec.begin(), vec.end());
		int l=0, r=n-1;
		while(l<r)
			cout<<vec[r--]<<" "<<vec[l++]<<" ";
		if(l==r)
			cout<<vec[l];
		cout<<endl;
	}
	return 0;
}