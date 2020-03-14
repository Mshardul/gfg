#include<iostream>
#include<vector>

using namespace std;

void Print(vector<int> vec){
	vector<int>::iterator iter = vec.begin();
	cout<<"-----------\n";
	while(iter!=vec.end()){
		cout<<*iter<<" ";
		iter++;
	}
	cout<<*(vec.begin())<<endl;
	cout<<"-----------\n";
}

bool Backtrack(vector<vector<int> > graph, int n, vector<int> temp, vector<bool> isVisited){
	if(temp.size()==n){
		if(graph[temp.back()][temp.front()]==1){
			Print(temp);
			return true;
		}else{
			return false;
		}
	}
	for(int i=0; i<n; i++){
		if(temp.empty()){
			temp.push_back(i);
			isVisited[i] = true;
		}else{
			int currVec = temp.back();
			if(isVisited[i]==false && graph[currVec][i]==1){
				temp.push_back(i);
				isVisited[i] = true;
			}else{
				continue;
			}
		}
		bool isHamil = Backtrack(graph, n, temp, isVisited);
		if(isHamil)
			return true;
		temp.pop_back();
		isVisited[i] = false;
	}
	return false;
}

void Hamiltonian(vector<vector<int> > graph, int n){
	vector<int> temp;
	vector<bool> isVisited(n, false);
	bool isHamil = false;
	isHamil = Backtrack(graph, n, temp, isVisited);
	if(!isHamil)
		cout<<"no Hamiltonian path\n";
}

int main(int argc, char const *argv[]) {
	int n;
	cin>>n;
	vector<vector<int> > graph;
	graph.resize(n, vector<int>(n));
	for(int i=0; i<n; i++)
		for(int j=0; j<n; j++)
			cin>>graph[i][j];
	Hamiltonian(graph, n);
	return 0;
}