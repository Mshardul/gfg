#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

// #define ll long long

void Print(vector<int> vec){
	vector<int>::iterator iter = vec.begin();
	while(iter!=vec.end()){
		cout<<*iter<<" ";
		iter++;
	}
	cout<<endl;
}

bool cmp(int x, int y){
	return x>y;
}

vector<int> SortInOrder(vector<int> vec, int n){
	vector<int> odd;
	vector<int> even;
	for(int i=0; i<n; i++){
		if(vec[i]%2==0)
			even.push_back(vec[i]);
		else
			odd.push_back(vec[i]);
	}
	sort(even.begin(), even.end());
	sort(odd.begin(), odd.end(), greater<int>());
	int m = even.size();
	for(int i=0; i<m; i++)
		odd.push_back(even[i]);
	return odd;
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
		vector<int> res = SortInOrder(vec, n);
		Print(res);
	}
	return 0;
}