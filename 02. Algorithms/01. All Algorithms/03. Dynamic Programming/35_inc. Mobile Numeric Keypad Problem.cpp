//can be done using bfs of length 'n'
//create graphs.
/*
1-----2-----3
|     |     |
4-----5-----6
|     |     |
7-----8-----9
      |
      0
*/


#include<iostream>
#include<vector>

using namespace std;

void Print(vector<vector<int> > vec){
	int n = vec.size();
	for(int i=0; i<n; i++){
		int m = vec[i].size();
		for(int j=0; j<m; j++)
			cout<<vec[i][j]<<" ";
		cout<<endl;
	}
}

int func(vector<vector<int> > Neighbors, int n){ //this should work
	int ans = 0;
	vector<vector<int> > dp;
	dp.resize(n, 10);
	for(int i=0; i<10; i++){
		dp[0][i] = Neighbors[i].size();
	}
	
	for(int i=1; i<n; i++){
		for(int j=0; j<10; j++){
			vector<int> next = Neighbors[j];
			int nxt = 0;
			for(int k=0; k<next.size(); k++){
				nxt += dp[i-1][next[k]];
			}
			dp[i][j] = nxt;
		}
	}
	
	Print(dp);
}

int main(int argc, char const *argv[]) {
	vector<vector<int> > Neighbors;
	// Neighbors.push_back(temp);
	Neighbors = {{0, 8}, {1, 2, 4}, {1, 2, 3, 5}, {2, 3, 6}, {1, 4, 5, 7}, {2, 4, 5, 6, 8}, {3, 5, 6, 9}, {4, 7, 8}, {0, 5, 7, 8, 9}, {6, 8, 9}}; //not working
	
	int k;
	cin>>k;
	
	cout<<func(Neighbors, k)<<endl;
	return 0;
}