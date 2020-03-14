#include<iostream>
#include<vector>

using namespace std;

void Print(vector<int> vec){
	vector<int>::iterator iter = vec.begin();
	while(iter!=vec.end()){
		cout<<*iter<<" ";
		iter++;
	}
	cout<<endl;
}

vector<int> Reverse(vector<int> vec){
	vector<int> ret;
	vector<int>::reverse_iterator iter = vec.rbegin();
	while(iter!=vec.rend()){
		ret.push_back(*iter);
		iter++;
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
		vector<int> ret = Reverse(vec);
		Print(ret);
	}
	return 0;
}