#include<iostream>
#include<vector>
#include<queue>

using namespace std;

#define V 9

/*
void Print(vector<int> vec){
	vector<int>::iterator iter = vec.begin();
	while(iter!=vec.end()){
		cout<<*iter<<" ";
		iter++;
	}
	cout<<endl;
}

int GetNextVertex(vector<int> dist, vector<bool> isIncl){
	int min=INT_MAX;
	int nextVertex;
	for(int i=0; i<V; i++){
		if(isIncl[i]==false && dist[i]<=min){
			min = dist[i];
			nextVertex = i;
		}
	}
	return nextVertex;
}

void dijkstra(int graph[V][V], int src){
	vector<int> dist(V, INT_MAX);
	vector<int> parent(V, -1);
	vector<bool> isIncl(V, false);
	dist[src] = 0;
	for(int i=0; i<V; i++){
		int v = GetNextVertex(dist, isIncl);
		cout<<v<<endl;
		isIncl[v] = true;
		for(int j=0; j<V; j++){
			if(isIncl[j]==false && graph[v][j]!=0 && dist[j]>dist[v]+graph[v][j]){
				dist[j] = dist[v]+graph[v][j];
				parent[j] = v;
			}
		}
		Print(dist);
		Print(parent);
		cout<<"------------\n";
	}
}

int main(int argc, char const *argv[]) {
	int graph[V][V] = {{0, 4, 0, 0, 0, 0, 0, 8, 0},
										{4, 0, 8, 0, 0, 0, 0, 11, 0},
										{0, 8, 0, 7, 0, 4, 0, 0, 2},
										{0, 0, 7, 0, 9, 14, 0, 0, 0},
										{0, 0, 0, 9, 0, 10, 0, 0, 0},
										{0, 0, 4, 14, 10, 0, 2, 0, 0},
										{0, 0, 0, 0, 0, 2, 0, 1, 6},
										{8, 11, 0, 0, 0, 0, 1, 0, 7},
										{0, 0, 2, 0, 0, 0, 6, 7, 0}
									};
	dijkstra(graph, 0);
	return 0;
}
*/

struct AdjListNode {
	int dest;
	int weight;
	struct AdjListNode* next;
};

struct AdjList {
	struct AdjListNode *head;
};

struct Graph {
	int V;
	struct AdjList* array;
};
  
struct AdjListNode* newAdjListNode(int dest, int weight) {
	struct AdjListNode* newNode = new struct AdjListNode();
	newNode->dest = dest;
	newNode->weight = weight;
	newNode->next = NULL;
	return newNode;
}

struct Graph* createGraph(int V) {
	struct Graph* graph = new struct Graph();
	graph->V = V;
	graph->array = new struct AdjList();
	for (int i = 0; i < V; ++i)
		graph->array[i].head = NULL;
	return graph;
} 

void addEdge(struct Graph* graph, int src, int dest, int weight) {
	struct AdjListNode* newNode = newAdjListNode(dest, weight);
	newNode->next = graph->array[src].head;
	graph->array[src].head = newNode;
	newNode = newAdjListNode(src, weight);
	newNode->next = graph->array[dest].head;
	graph->array[dest].head = newNode;
}

void dijkstra(struct Graph* graph, int src){ //incomplete
	vector<int> dist(V, INT_MAX);
	vector<int> parent(V, -1);
	vector<bool> isIncl(V, false);
	dist[src] = 0;
	priority_queue<pair<int, pair<int, int> > > q;
	int currVertex = src;
	int count = 1;
	while(count<V){
		struct AdjListNode* temp = graph->array[currVertex].head;
		while(temp!=NULL){
			q.insert(make_pair(temp->weight, make_pair(currVertex, temp->dest)));
			temp = temp->next;
		}
		while(1){
			pair<int, pair<int, int> > tp = q.top();
			int wt = tp.first;
			int v1 = tp.second.first;
			int v2 = tp.second.second;
			if(isIncl[v1]==true && isIncl[v2]==true)
				continue;
			if()
		}
	}
}

int main() {
	int V = 9; 
	struct Graph* graph = createGraph(V); 
	addEdge(graph, 0, 1, 4); 
	addEdge(graph, 0, 7, 8); 
	addEdge(graph, 1, 2, 8); 
	addEdge(graph, 1, 7, 11); 
	addEdge(graph, 2, 3, 7); 
	addEdge(graph, 2, 8, 2); 
	addEdge(graph, 2, 5, 4); 
	addEdge(graph, 3, 4, 9); 
	addEdge(graph, 3, 5, 14); 
	addEdge(graph, 4, 5, 10); 
	addEdge(graph, 5, 6, 2); 
	addEdge(graph, 6, 7, 1); 
	addEdge(graph, 6, 8, 6); 
	addEdge(graph, 7, 8, 7); 

	dijkstra(graph, 0); 
  
	return 0; 
} 