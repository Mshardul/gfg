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

int row(vector<vector<int> > vec, int n, int m){
	vector<int> ans(n, 0);
	for(int i=0; i<n; i++){
		for(int j=0; j<m; j++)
			ans[i] += vec[i][j];
	}
	Print(ans);
  int mx = 0;
	int ind = 0;
	for(int i=0; i<n; i++){
		if(vec[i]>mx){
			mx = vec[i];
			ind = i;
		}
	}
  return ind;
}

int main(){
  int t;
  cin>>t;
  while(t-->0){
		int n, m;
		cin>>n>>m;
		vector<vector<int> > vec;
		vec.resize(n, vector<int>(m));
		for(int i=0; i<n; i++){
			for(int j=0; j<m; j++)
				cin>>vec[i][j];
		}
		cout<<row(vec, n, m)<<endl;
	}
	return 0;
}