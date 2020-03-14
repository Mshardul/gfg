#include<iostream>
#include<vector>

using namespace std;

int maxPartition(vector<int> vec, int n, int k){ //should work
	sort(vec.begin(), vec.end());
	int sum = 0;
	int mid = (n%2==0)?(n/2)-1:(n/2);
	if(k<=mid){
		for(int i=0; i<k; i++)
			sum += vec[i];
	}else{
		for(int i=0; i<k; i++)
			sum += vec[n-1-i];
	}
	
	int total = 0;
	for(int i=0; i<n; i++)
		total += vec[i];
	return abs(total-(2*sum));
}

int main(int argc, char const *argv[]) {
	int n, k;
	cin>>n>>k;
	vector<int> vec(n);
	for(int i=0; i<n; i++)
		cin>>vec[i];
	cout<<maxPartition(vec, n, k)<<endl;
	return 0;
}