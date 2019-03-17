#include <iostream>
#include <vector>
#include <stack>
using namespace std;

//assuming no cycle
//check this once
class Graph{
	int n;
	vector<int> *vec;

public:
	Graph(int m){
		n=m;
		vec=new vector<int> [n];
	}

	void AddEdge(int u, int v){
		vec[u].push_back(v);
		vec[v].push_back(u);
	}

	void DisplayNeighbors(int u){
		for(vector<int>::iterator iter = vec[u].begin(); iter!=vec[u].end(); iter++){
			cout<<*iter<<" ";
		}
		cout<<endl;
	}

	void DFS(){
		int visited[n]; //0:not yet visited, 1:in the stack, 2: out of stack
		visited[0]=1;
		for(int i=1; i<n; i++)
			visited[i]=0;

		bool newNeighbor=true;

		stack<int> st;
		st.push(0);
		int u=0;
		
		while(!st.empty()){
			if(visited[u]==2){
				cout<<u<<" ";
				st.pop();
			}
			else{
				newNeighbor=false;
				for(vector<int>::iterator iter = vec[u].begin(); iter!=vec[u].end(); iter++){
					if(visited[*iter]!=2){
						newNeighbor=true;
						st.push(*iter);
						visited[*iter]=1;
					}
				}
				if(!newNeighbor){
					cout<<u<<" ";
					visited[u]=2;
					st.pop();
				}
			}
			u=st.top();
		}
		cout<<endl;
	}
};

int main(int argc, char const *argv[])
{
	Graph g(5);  // Total 5 vertices in graph 
	g.AddEdge(1, 0);
	g.AddEdge(2, 1);
	g.AddEdge(3, 4);
	g.AddEdge(4, 0);

	for(int i=0; i<5; i++)
		g.DisplayNeighbors(i);

	g.DFS();
	return 0;
}