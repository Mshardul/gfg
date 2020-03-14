#include<iostream>
#include<vector>
#include<map>
using namespace std;

int prims(int n, vector<unordered_map<int, int> > adj){
	int m = adj.size();
	vector<int> dist(n, INT_MAX); //INT_MAX:to visit, dist, INT_MIN: visited
	vector<
}

int main(int argc, char const *argv[]) { //incomplete
	int n, m;
	cin>>n;
	
	cin>>m;
	vector<unordered_map<int, int> > adj;
	int v1, v2, val;
	
	for(int i=0; i<m; i++){
		cin>>v1>>v2>>val;
		adj[v1].insert(val, v2);
		adj[v2].insert(val, v1);
	}
	
	cout<<prims(n, adj)<<endl;
	
	return 0;
}

/*adjacency matrix*/

# define V 5

#include<iostream>
#include<vector>
#include<queue>

using namespace std;

void Print(vector<pair<pair<int, int>, int> > vec){
	vector<pair<pair<int, int>, int> >::iterator iter = vec.begin();
	while(iter!=vec.end()){
		cout<<(iter->first).first<<" "<<(iter->first).second<<" "<<iter->second<<endl;
		iter++;
	}
}

pair<int, pair<int, int> > GetMinEdge(vector<priority_queue<pair<int, int>, vector<pair<int, int> > , greater<pair<int, int> > > > neighbors, vector<int> verticesVisited){
	pair<int, pair<int, int> > ans;
	int currMin = INT_MAX;
	for(int i=0; i<V; i++){
		if(verticesVisited[i]==-1 || neighbors[i].empty())
			continue;
		pair<int, int> p = neighbors[i].top();
		if(p.first<currMin){// && !neighbors[p.second].empty()){
			ans = make_pair(i, p);
			currMin = p.first;
		}
	}
	int v1 = ans.first;
	int v2 = ans.second.second;
	return ans;
}

void Print(vector< priority_queue<pair<int, int>, vector<pair<int, int> >, greater<pair<int, int> > > > neighbors){
	cout<<"----------\n";
	int n = neighbors.size();
	for(int i=0; i<n; i++){
		cout<<i<<endl;
		priority_queue<pair<int, int>, vector<pair<int, int> >, greater<pair<int, int> > > q = neighbors[i];
		while(!q.empty()){
			pair<int, int> p = q.top();
			cout<<p.second<<" "<<p.first<<endl;
			q.pop();
		}
	}
	cout<<"----------\n";
}

void primMST(int graph[V][V]){
	vector< priority_queue<pair<int, int>, vector<pair<int, int> >, greater<pair<int, int> > > > neighbors(V);
	
	for(int i=0; i<V; i++){
		for(int j=i+1; j<V; j++){
			if(graph[i][j]>0){
				neighbors[i].push(make_pair(graph[i][j], j));
			}
		}
	}
	
	// Print(neighbors); //all good
	
	vector<int> verticesVisited(V, -1);
	verticesVisited[0] = 0;
	int curr = 0;
	int count = 1;
	
	vector<pair<pair<int, int>, int> > ans;
	while(count<V){
		pair<int, pair<int, int> > p = GetMinEdge(neighbors, verticesVisited);
		int v1 = p.first;
		int v2 = p.second.second;
		int wt = p.second.first;
		neighbors[v1].pop();
		verticesVisited[v2] = v1;
		ans.push_back(make_pair(make_pair(v1, v2), wt));
		count++;
	}
	Print(ans);
}

int main() {
	int graph[V][V] = { { 0, 2, 0, 6, 0 },
											{ 2, 0, 3, 8, 5 },
											{ 0, 3, 0, 0, 7 },
											{ 6, 8, 0, 0, 9 },
											{ 0, 5, 7, 9, 0 } };
	primMST(graph);
	return 0;
}  