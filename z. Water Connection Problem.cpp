// works only for not more than one pipe from each house.

#include<iostream>
#include<vector>
#include<map>
using namespace std;

void Print(map<int, pair<int, int> > mp){
	cout<<mp.size()<<endl;
	map<int, pair<int, int> > ::iterator iter = mp.begin();
	while(iter!=mp.end()){
		cout<<iter->first<<" "<<(iter->second).first<<" "<<(iter->second).second<<endl;
		iter++;
	}
}

void DFS(map<int, pair<int, int> > &mp, vector<int> from, int n){
	for(int i=0; i<n; i++){
		int fr = from[i];
		map<int, pair<int, int> >::iterator iter = mp.find(fr);
		if(iter==mp.end())
			continue;
		int to = (iter->second).first;
		int di = (iter->second).second;
		while(1){
			map<int, pair<int, int> >::iterator iter2 = mp.find(to);
			if(iter2==mp.end())
				break;
			to = (iter2->second).first;
			di = min(di, (iter2->second).second);
			mp.erase(iter2);
		}
		(iter->second).first = to;
		(iter->second).second = di;
		cout<<i<<" "<<fr<<" "<<to<<" "<<di<<endl;
	}
}

int main(int argc, char const *argv[]) {
	int t;
	cin>>t;
	while(t-->0){
		int n, p;
		cin>>n>>p;
		map<int, pair<int, int> > mp;
		vector<int> hFrom;
		int temp1, temp2, temp3;
		int uniq = p;
		for(int i=0; i<p; i++){
			cin>>temp1>>temp2>>temp3;
			if(mp.find(temp1)!=mp.end()){ //just in case of multiple pipes from same house
				mp[temp1] = make_pair(temp2, temp3);
				uniq--;
				continue;
			}
			mp.insert(make_pair(temp1, make_pair(temp2, temp3)));
			hFrom.push_back(temp1);
		}
		p = uniq;
		DFS(mp, hFrom, p);
		Print(mp);
	}
	return 0;
}