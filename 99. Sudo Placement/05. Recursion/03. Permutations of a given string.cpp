#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

void Print(vector<string> vec){
	vector<string>::iterator iter = vec.begin();
	while(iter!=vec.end()){
		cout<<*iter<<" ";
		iter++;
	}
	cout<<endl;
}

void Recurse(string s, int l, int r, vector<string>&vec){ //will contain duplicate
	if(l==r){
		vec.push_back(s);
	}else{
		for(int i=l; i<=r; i++){
			swap(s[l], s[i]);
			Recurse(s, l+1, r, vec); //keep 'l' intact, permute on remaining string
			swap(s[l], s[i]);
		}
	}
}

void Permutations(string s){
	int n = s.size();
	vector<string> vec;
	Recurse(s, 0, n-1, vec);
	sort(vec.begin(), vec.end());
	Print(vec);
}

int main(int argc, char const *argv[]) {
	int t;
	cin>>t;
	while(t-->0){
		string s;
		cin>>s;
		Permutations(s);
	}
	return 0;
}