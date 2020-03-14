#include<iostream>
#include<vector>

using namespace std;

struct edge{
	int v1, v2, val;
};

struct edge newEdge(int v1, int v2, int val){
	struct edge *temp = new struct edge();
	temp->v1 = v1;
	temp->v2 = v2;
	temp->val = val;
	return *temp;
}

void Print(vector<vector<int> > vec, int n){
	for(int i=0; i<n; i++){
		for(int j=0; j<n; j++)
			cout<<vec[i][j]<<" ";
		cout<<endl;
	}
	cout<<"------------\n";
}

void floydWarshall(vector<struct edge> edges, int m, int n){
	vector<vector<int> > dp;
	dp.resize(n, vector<int>(n));
	
	for(int i=0; i<n; i++){
		for(int j=0; j<n; j++){
			if(dp[i][j]==0 && i!=j){
				dp[i][j] = INT_MAX;
			}
		}
	}
	
	for(int i=0; i<m; i++){
		edge e = edges[i];
		dp[e.v1][e.v2] = e.val;
		dp[e.v2][e.v1] = e.val;
	}
	
	Print(dp, n);
	
	for(int i=0; i<n; i++){
		for(int j=0; j<n; j++){
			for(int k=0; k<n; k++){
				if(dp[i][k]!=INT_MAX && dp[k][j]!=INT_MAX && (dp[i][k]+dp[k][j]<dp[i][j]))
					dp[i][j] = dp[i][k]+dp[k][j];
			}
		}
	}
	
	Print(dp, n);
}

int main(int argc, char const *argv[]) {
	int n, m;
	cin>>n>>m;
	
	vector<struct edge> edges;
	int v1, v2, val;
	for(int i=0; i<m; i++){
		cin>>v1>>v2>>val;
		edges.push_back(newEdge(v1, v2, val));
	}
	
	floydWarshall(edges, m, n);
	return 0;
}