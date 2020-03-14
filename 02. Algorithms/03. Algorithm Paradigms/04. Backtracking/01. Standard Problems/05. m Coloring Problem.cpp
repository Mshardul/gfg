#include<iostream>
#include<vector>

using namespace std;

void Print(vector<int> vec){
	vector<int>::iterator iter = vec.begin();
	while(iter!=vec.end()){
		cout<<*iter<<" ";
		iter++;
	}
	cout<<endl;
}

bool isColorable(vector<vector<int> > graph, int n, int v, int c, vector<int> color){
	for(int i=0; i<n; i++){
		if(graph[v][i]==1 && color[i]==c){ //neighbour is also colored c
			return false;
		}
	}
	return true;
}

bool Backtrack(vector<vector<int> > graph, int n, vector<int> color, int v, int c){
	if(v>=n){
		Print(color);
		return true;
	}
	for(int i=0; i<=c; i++){
		if(isColorable(graph, n, v, i, color)){
			color[v] = i;
			bool isValid = Backtrack(graph, n, color, v+1, c);
			if(isValid)
				return true;
		}
	}
	color[v] = c+1;
	bool isValid = Backtrack(graph, n, color, v, c+1);
	return isValid;
}

void color(vector<vector<int> > graph, int n){
	vector<int> color(n, -1);
	bool isColorable;
	isColorable = Backtrack(graph, n, color, 0, 0);
	if(!isColorable)
		cout<<"cannot be colored\n";
}

int main(int argc, char const *argv[]) {
	int n;
	cin>>n;
	vector<vector<int> > graph;
	graph.resize(n, vector<int>(n));
	for(int i=0; i<n; i++)
		for(int j=0; j<n; j++)
			cin>>graph[i][j];
	color(graph, n);
	return 0;
}