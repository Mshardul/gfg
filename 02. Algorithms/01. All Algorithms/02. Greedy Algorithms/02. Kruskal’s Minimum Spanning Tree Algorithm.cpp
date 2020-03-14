#include<iostream>
#include<vector>
#include<map>
#include<set>
using namespace std;

struct edge{
	int v1, v2, val;
};

struct edge newEdge(int v1, int v2, int val){
	struct edge *e = new struct edge();
	e->v1 = v1;
	e->v2 = v2;
	e->val = val;
	return *e;
}

void Print(map<int, pair<int, int> > mp){
	map<int, pair<int, int> >::iterator iter = mp.begin();
	cout<<"-------------\n";
	while(iter!=mp.end()){
		cout<<iter->first<<" "<<(iter->second).first<<" "<<(iter->second).second<<endl;
		iter++;
	}
	cout<<"-------------\n";
}

void PrintEdges(vector<edge> e){
	int m = e.size();
	cout<<"-------------\n";
	for(int i=0; i<m; i++)
		cout<<e[i].v1<<" "<<e[i].v2<<" "<<e[i].val<<endl;
	cout<<"-------------\n";	
}

int kruskal(int n, vector<edge> e){
	int ans = 0;
	vector<int> vis(n, false);
	
	int m = e.size();
	map<int, pair<int, int> > mp;
	
	for(int i=0; i<m; i++){
		edge temp = e[i];
		mp.insert(make_pair(temp.val, make_pair(temp.v1, temp.v2)));
	}
	
	map<int, pair<int, int> >::iterator iter = mp.begin();
	while(iter!=mp.end()){
		int val = iter->first;
		pair<int, int> vertices = iter->second;
		if((vis[vertices.first] && !vis[vertices.second]) || (!vis[vertices.first] && vis[vertices.second]) || (!vis[vertices.first] && !vis[vertices.second])){
			cout<<vertices.first<<" "<<vertices.second<<" "<<val<<endl;
			vis[vertices.first] = true;
			vis[vertices.second] = true;
			ans += val;
		}
		iter++;
	}
	
	return ans;
}

int main(int argc, char const *argv[]) {
	int n, m;
	cin>>n;
	
	cin>>m;
	vector<edge> e;
	int v1, v2, val;
	for(int i=0; i<m; i++){
		cin>>v1>>v2>>val;
		struct edge temp = newEdge(v1, v2, val);
		e.push_back(temp);
	}
	
	PrintEdges(e);
	cout<<kruskal(n, e)<<endl;
	
	return 0;
}



/*adjacency matrix approach*/
struct Edge {
	int src, dest, weight;
};

struct Graph {
	int V, E;
	struct Edge* edge;
};

void Print(vector<Edge> vec){
	vector<Edge>::iterator iter = vec.begin();
	while(iter!=vec.end()){
		cout<<iter->src<<" "<<iter->dest<<" "<<iter->weight<<endl;
		iter++;
	}
	cout<<endl;
}

struct Graph* createGraph(int V, int E) {
	struct Graph* graph = new Graph;
	graph->V = V;
	graph->E = E;
  graph->edge = new Edge[E];
  return graph;
}

void KruskalMST(struct Graph* graph){
	priority_queue<pair<int, pair<int, int> >, vector<pair<int, pair<int, int> > >, greater<pair<int, pair<int, int> > > > q;
	int ed = graph->E;
	for(int i=0; i<ed; i++){
		Edge temp = (graph->edge)[i];
		q.push(make_pair(temp.weight, make_pair(temp.src, temp.dest)));
	}
	pair<int, pair<int, int> > mp;
	set<int> verticesVisited;
	vector<Edge> MST;
	while(!q.empty()){
		mp = q.top();
		q.pop();
		int wt = mp.first;
		int v1 = mp.second.first;
		int v2 = mp.second.second;
		if(verticesVisited.find(v1)!=verticesVisited.end() && verticesVisited.find(v2)!=verticesVisited.end())
			continue;
		Edge *e = new struct Edge();
		e->src = v1;
		e->dest = v2;
		e->weight = wt;
		MST.push_back(*e);
		verticesVisited.insert(v1);
		verticesVisited.insert(v2);
	}
	Print(MST);
}

int main() {
	int V = 4;
	int E = 5;
	struct Graph* graph = createGraph(V, E);
	// add edge 0-1 
	graph->edge[0].src = 0;
	graph->edge[0].dest = 1;
	graph->edge[0].weight = 10;
	// add edge 0-2 
	graph->edge[1].src = 0;
	graph->edge[1].dest = 2;
	graph->edge[1].weight = 6;
	// add edge 0-3 
	graph->edge[2].src = 0;
	graph->edge[2].dest = 3;
	graph->edge[2].weight = 5;
	// add edge 1-3
	graph->edge[3].src = 1;
	graph->edge[3].dest = 3;
	graph->edge[3].weight = 15;
	// add edge 2-3 
	graph->edge[4].src = 2;
	graph->edge[4].dest = 3;
	graph->edge[4].weight = 4;
	KruskalMST(graph);
	return 0;
} 