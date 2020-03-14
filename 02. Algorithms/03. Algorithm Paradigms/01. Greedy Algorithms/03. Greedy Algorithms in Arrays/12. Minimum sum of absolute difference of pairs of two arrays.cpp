#include<iostream>
#include<vector>

using namespace std;

int sum(vector<int> vec1, vector<int> vec2, int n){
	sort(vec1.begin(), vec1.end());
	sort(vec2.begin(), vec2.end());
	int sum = 0;
	for(int i=0; i<n; i++)
		sum += abs(vec1[i]-vec2[i]);
	return sum;
}

int main(int argc, char const *argv[]) {
	int n;
	cin>>n;
	vector<int> vec1(n);
	for(int i=0; i<n; i++)
		cin>>vec1[i];
	vector<int> vec2(n);
	for(int i=0; i<n; i++)
		cin>>vec2[i];
	cout<<sum(vec1, vec2, n);
	return 0;
}