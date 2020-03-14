#include<iostream>
#include<vector>
#include<queue>

using namespace std;

void Print(vector<int> vec){
	vector<int>::iterator iter = vec.begin();
	while(iter!=vec.end()){
		cout<<*iter<<" ";
		iter++;
	}
	cout<<endl;
}

vector<int> Maximum(vector<int> vec, int k, int n){
	if(k==1)
		return vec;
	vector<int> ret;
	deque<int> q;
	int i=0;
	while(i<k){ //get numbers in strictly decreasing order in first 'k' indices
		if(!q.empty() && vec[q.back()]<=vec[i])
			q.pop_back();
		else
			q.push_back(i++);
	}
	while(i<n){ //for the remaining error, pop unnecessary values from front, and repeat the previous step from back
		ret.push_back(vec[q.front()]);
		while(!q.empty() && q.front()<=i-k)
			q.pop_front();
		while(!q.empty() && vec[q.back()]<=vec[i])
			q.pop_back();
		q.push_back(i++);
	}
	ret.push_back(vec[q.front()]);
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
		vector<int> ret = Maximum(vec, k, n);
		Print(ret);
	}
	return 0;
}