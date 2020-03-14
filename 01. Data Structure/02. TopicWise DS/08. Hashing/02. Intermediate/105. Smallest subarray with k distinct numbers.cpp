#include<iostream>
#include<vector>
#include<unordered_map>

using namespace std;

void Print(unordered_map<int, int> mp){
	unordered_map<int, int>::iterator iter = mp.begin();
	while(iter!=mp.end()){
		cout<<(*iter).first<<" "<<(*iter).second<<"  ";
		iter++;
	}
	cout<<endl;
}

pair<int, int> GetRange(vector<int> vec, int n, int k){ //assuming k>0
	if(k==1)
		return make_pair(0, 0);
	int l=0, r=0, uniq=1, minDiff=INT_MAX;
	unordered_map<int, int> mp;
	pair<int, int> ans;
	mp[0] = 1;
	while(r<n){
		if(uniq>=k){
			if(uniq==k && (r-l)<minDiff){
				minDiff = r-l;
				ans.first = l;
				ans.second = r;
			}
			if(l<r){
				mp[l]--;
				if(mp[l]==0)
					uniq--;
				l++;
			}else{
				r++;
				if(mp.find(r)==mp.end()){
					mp[r] = 1;
					uniq++;
				}else
					mp[r]++;
			}
		}else{
			r++;
			if(mp.find(r)==mp.end()){
				mp[r] = 1;
				uniq++;
			}else
				mp[r]++;
		}
		cout<<l<<" "<<r<<" "<<uniq<<endl;
		// Print(mp);
	}
	return ans;
}

int main(int argc, char const *argv[]) {
	int n;
	cin>>n;
	vector<int> vec(n);
	for(int i=0; i<n; i++)
		cin>>vec[i];
	int k;
	cin>>k;
	pair<int, int> ans = GetRange(vec, n, k);
	cout<<ans.first<<" "<<ans.second<<endl;
	return 0;
}