#include<iostream>
#include<vector>
#include<deque>
#include<map>
using namespace std;

void Print(deque<string> vec){
	deque<string>::iterator iter = vec.begin();
	while(iter!=vec.end()){
		cout<<*iter<<" ";
		iter++;
	}
	cout<<endl;
}

deque<string> phone(vector<int> vec, map<int, string>mp, int n){
	deque<string> ret;
	if(n==0)
		return ret;

	string st = mp[vec[0]];
	for(char ch:st)
		ret.push_back(string(1, ch));
	for(int i=1; i<n; i++){
		int len = ret.size();
		string st = mp[vec[i]];
		for(int j=0; j<len; j++){
			string temp = ret.front();
			ret.pop_front();
			for(char ch:st)
				ret.push_back(temp+string(1, ch));
		}
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
		map<int, string> mp;
		mp.insert(make_pair(2, "abc"));
		mp.insert(make_pair(3, "def"));
		mp.insert(make_pair(4, "ghi"));
		mp.insert(make_pair(5, "jkl"));
		mp.insert(make_pair(6, "mno"));
		mp.insert(make_pair(7, "pqrs"));
		mp.insert(make_pair(8, "tuv"));
		mp.insert(make_pair(9, "wxyz"));
		deque<string> ret = phone(vec, mp, n);
		Print(ret);
	}
	return 0;
}