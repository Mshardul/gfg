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

vector<int> Rotate(vector<int> vec, int n, int k){
	vector<int> ret;
	for(int i=k; i<n; i++)
		ret.push_back(vec[i]);
	for(int i=0; i<k; i++)
		ret.push_back(vec[i]);
	return ret;
}

int main(int argc, char const *argv[]) {
	int t;
	cin>>t;
	while(t-->0){
		int n;
		cin>>n;
		vector<int> vec(n);
		for(int i=0; i<n; i++)
			cin>>vec[i];
		int k;
		cin>>k;
		vector<int> ret = Rotate(vec, n, k);
		Print(ret);
	}
	return 0;
}