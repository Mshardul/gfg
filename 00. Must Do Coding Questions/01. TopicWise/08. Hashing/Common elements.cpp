#include<iostream>
#include<vector>
#include<unordered_map>

using namespace std;

void Print(vector<int> vec){
	if(vec.empty()){
		cout<<"-1\n";
		return;
	}
	vector<int>::iterator iter = vec.begin();
	while(iter!=vec.end()){
		cout<<(*iter)<<" ";
		iter++;
	}
	cout<<endl;
}

vector<int> GetCommon(vector<int> vec1, int x, vector<int> vec2, int y, vector<int> vec3, int z){
	vector<int> vec;
	unordered_map<int, bool> mp;
	int i=0, j=0, k=0;
	while(i<x && j<y && k<z){
		int val1 = vec1[i];
		int val2 = vec2[j];
		int val3 = vec3[k];
		int ans;
		if(vec1[i]==vec2[j] && vec2[j]==vec3[k]){
			if(mp.find(vec1[i])==mp.end()){
				vec.push_back(vec1[i]);
				mp.insert(make_pair(vec1[i], true));
			}
			i++;
			j++;
			k++;
		}else if(vec1[i]<vec2[j]){
			i++;
		}else if(vec2[j]<vec3[k]){
			j++;
		}else{
			k++;
		}
	}
	return vec;
}

int main(int argc, char const *argv[]) {
	int t;
	cin>>t;
	while(t-->0){
		int x, y, z;
		cin>>x>>y>>z;
		vector<int> vec1(x);
		for(int i=0; i<x; i++)
			cin>>vec1[i];
			
		vector<int> vec2(y);
		for(int i=0; i<y; i++)
			cin>>vec2[i];
			
		vector<int> vec3(z);
		for(int i=0; i<z; i++)
			cin>>vec3[i];
		
		vector<int> vec = GetCommon(vec1, x, vec2, y, vec3, z);
		Print(vec);
	}
	return 0;
}