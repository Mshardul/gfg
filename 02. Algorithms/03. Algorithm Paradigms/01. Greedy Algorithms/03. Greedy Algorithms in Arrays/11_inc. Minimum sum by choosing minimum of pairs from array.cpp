//didnt understand the question properly

#include<iostream>
#include<vector>

using namespace std;

int sum(vector<int> vec, int n){ //didnt understand the question properly
	vector<int> res;
	for(int i=0; i<n; i+=2)
		res.push_back(min(vec[i], vec[i+1]));
	vector<int>::iterator iter = res.begin();
	int sum = 0;
	while(iter!=res.end()){
		sum += *iter;
		iter++;
	}
	return sum;
}

int main(int argc, char const *argv[]) {
	int n;
	cin>>n;
	vector<int> vec(n);
	for(int i=0; i<n; i++)
		cin>>vec[i];
	cout<<sum(vec, n)<<endl;
	return 0;
}