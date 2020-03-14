#include<iostream>
#include<vector>
#include<map>

using namespace std;

void Print(vector<int> vec){
	vector<int>::iterator iter = vec.begin();
	while(iter!=vec.end()){
		cout<<*iter<<" ";
		iter++;
	}
	cout<<endl;
}

void Print(map<int, int> mp){
	map<int, int>::iterator iter = mp.begin();
	while(iter!=mp.end()){
		cout<<iter->first<<" "<<iter->second<<endl;
		iter++;
	}
	cout<<endl;
}

vector<int> distinct(vector<int> vec, int k, int n){
	vector<int> ret;
	map<int, int> mp;
	int i = 0;
	int uniq = 0;
	while(i<k){
		if(mp.find(vec[i])==mp.end()){
			uniq++;
			mp.insert(make_pair(vec[i], 1));
		}else{
			mp[vec[i]]++;
		}
		i++;
	}
	
	ret.push_back(uniq);

	while(i<n){
		int excl = vec[i-k];
		int incl = vec[i];
		
		if(incl==excl){
			i++;
			ret.push_back(uniq);
			continue;
		}
		
		if(mp.find(incl)==mp.end()){
			mp.insert(make_pair(incl, 1));
			uniq++;
		}else{
			mp[incl]++;
			if(mp[incl]==1)
				uniq++;
		}
		
		mp[excl]--;
		if(mp[excl]==0)
			uniq--;
			
		ret.push_back(uniq);
		i++;
	}
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
		vector<int> res = distinct(vec, k, n);
		Print(res);
	}
	return 0;
}