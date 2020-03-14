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

vector<int> ReverseGroups(vector<int> vec, int n, int k){
	vector<int> ret;
	int grp = n/k;
	int l, r;
	for(int i=0; i<grp; i++){
		l=i*k;
		r=((i+1)*k)-1;
		while(r>=l)
			ret.push_back(vec[r--]);
	}
	r = (grp*k);
	while(n>r)
		ret.push_back(vec[--n]);
	return ret;
}

int main(int argc, char const *argv[]) {
	int t;
	cin>>t;
	while(t-->0){
		int n, k;
		cin>>n>>k;
		vector<int> vec(n);
		for(int i=0; i<n; i++)
			cin>>vec[i];
		vector<int> ret = ReverseGroups(vec, n, k);
		Print(ret);
	}
	return 0;
}