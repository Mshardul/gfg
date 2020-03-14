#include<iostream>
#include<unordered_map>
#include<map>
// #include<queue>
#include<vector>
#include<bits/stdc++.h>

using namespace std;

void Print(unordered_map<int, int> vec){
	unordered_map<int, int> ::iterator iter = vec.begin();
	cout<<"---------------\n";
	while(iter!=vec.end()){
		cout<<iter->first<<" "<<iter->second<<endl;
		iter++;
	}
	cout<<"---------------\n";
}

void activitySelection(int n){ //method1
	map<int, int> mp;
	int s, e;
	for(int i=0; i<n; i++){
		cin>>s>>e;
		mp.insert(make_pair(e, s));
	}
	unordered_map<int, int> ret;
	pair<int, int> prev = *(mp.begin());
	ret.insert(prev);
	map<int, int>::iterator iter = mp.begin();
	iter++;
	while(iter!=mp.end()){
		if(prev.first <= iter->second){
			prev = *(iter);
			ret.insert(*iter);
		}
		iter++;
	}
	Print(ret);
}

void activitySelection2(int n){ //method2
	vector<int> s(n);
	vector<int> e(n);
	
	for(int i=0; i<n; i++)
		cin>>s[i]>>e[i];
	
	priority_queue<pair<int, int>, vector<pair<int, int> >, greater<pair<int, int> > > pq;
	for(int i=0; i<n; i++)
		pq.push(make_pair(e[i], s[i]));
	
	unordered_map<int, int> ret;
	pair<int, int> prev = pq.top();
	pq.pop();
	ret.insert(prev);
	
	while(!pq.empty()){
		pair<int, int> curr = pq.top();
		if(prev.first<=curr.second){
			ret.insert(curr);
			prev = curr;
		}
		pq.pop();
	}
	Print(ret);
}

int main(int argc, char const *argv[]) {
	int n;
	cin>>n;
	// activitySelection(n); //method1
	activitySelection2(n); //method2
	return 0;
}