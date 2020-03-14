#include<iostream>
#include<vector>
#include<unordered_map>

using namespace std;

void findNum(vector<int> vec, int k){
	unordered_map<int, pair<int, int> > mp;
	int n = vec.size();
	
	for(int i=0; i<n; i++){
		for(int j=i+1; j<n; j++)
			mp[vec[i]+vec[j]] = make_pair(vec[i], vec[j]);
	}
	
	for(int i=0; i<n; i++){
		for(int j=i+1; j<n; j++){
			int to_find = k-(vec[i]+vec[j]);
			if(mp.find(to_find)!=mp.end()){
				pair<int, int> temp = mp[to_find];
				if(temp.first!=vec[i] && temp.second!=vec[i] && temp.first!=vec[j] && temp.second!=vec[j])
					cout<<vec[i]<<" "<<vec[j]<<" "<<vec[temp.first]<<" "<<vec[temp.second]<<" $";
			}
		}
	}
	cout<<endl;
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
		
		sort(vec.begin(), vec.end());
		findNum(vec, k);
	}
	return 0;
}