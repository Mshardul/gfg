#include<iostream>
#include<vector>
#include<stack>

using namespace std;

void PrintRev(vector<int> vec){
	vector<int>::reverse_iterator iter = vec.rbegin();
	while(iter!=vec.rend()){
		cout<<*iter<<" ";
		iter++;
	}
	cout<<endl;
}

vector<int> GetLeaders(vector<int> vec, int n){
	vector<int> ret;
	stack<int> st;
	int i=0;
	while(i<n){
		if(!st.empty() && vec[st.top()]<vec[i])
			st.pop();
		else
			st.push(i++);
	}
	while(!st.empty()){
		ret.push_back(vec[st.top()]);
		st.pop();
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
		vector<int> ret = GetLeaders(vec, n);
		PrintRev(ret);
	}
	return 0;
}