#include<iostream>
#include<vector>

using namespace std;

struct val{
	int first;
	int second;
};

void Print(vector<pair<int, int> > vec, int n){
	for(int i=0; i<n; i++)
		cout<<vec[i].first<<" "<<vec[i].second<<endl;
}

void GetMaxLen(struct val p[], int n){
	vector<pair<int, int> > vec;
	for(int i=0; i<n; i++)
		vec.push_back(make_pair(p[i].first, p[i].second));
	sort(vec.begin(), vec.end());
	Print(vec, n);
}

int main(int argc, char const *argv[]) {
	int t;
	cin>>t;
	while(t-->0){
		int n;
		cin>>n;
		val p[n];
		for(int i=0; i<n; i++)
			cin>>p[i].first>>p[i].second;
		GetMaxLen(p, n);
	}
	return 0;
}