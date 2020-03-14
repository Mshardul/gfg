#include<iostream>
#include<vector>

using namespace std;

int stackBoxes(vector<vector<int> > vec, int n){
	
}

int main(int argc, char const *argv[]) {
	int t;
	cin>>t;
	while(t-->0){
		int n;
		cin>>n;
		
		vector<int> height(n);
		vector<int> width(n);
		vector<int> length(n);
		
		for(int i=0; i<n; i++)
			cin>>height[i]>>width[i]>>length[i];

		cout<<stackBoxes(vec, n);
	}
	return 0;
}