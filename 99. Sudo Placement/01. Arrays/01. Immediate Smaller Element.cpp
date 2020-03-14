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

vector<int> ImmSmaller(vector<int> vec, int n){
	vector<int> ret(n, -1);
	for(int i=0; i<n-1; i++){
		if(vec[i]>vec[i+1])
			ret[i] = vec[i+1];
	}
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
		vector<int> res = ImmSmaller(vec, n);
		Print(res);
	}
	return 0;
}