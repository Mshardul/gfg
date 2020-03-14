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

bool isSortable(vector<int> vec, int n){
	vector<int> res(n);
	int l = 0, r = n-1;
	while(l<r){
		res[l] = min(vec[l], vec[r]);
		res[r] = max(vec[l], vec[r]);
		l++; r--;
	}
	if(n%2==1)
		res[l] = vec[l];
	Print(res);
	for(int i=1; i<n; i++)
		if(res[i]<res[i-1])
			return false;
	return true;
}

int main(int argc, char const *argv[]) {
	int n;
	cin>>n;
	vector<int> vec(n);
	for(int i=0; i<n; i++)
		cin>>vec[i];
	cout<<isSortable(vec, n)<<endl;
	return 0;
}