#include<iostream>
#include<vector>
#include<climits>

using namespace std;

int nearestSmaller(vector<int> vec, int val, int n){
	int l=0, r=n-1;
	int ans = vec[0];
	while(l<r){
		int mid = (l+(r-l)/2);
		if(vec[mid]<val)
			l = mid+1;
		else if(vec[mid]>val)
			r = mid;
		else
			return val;
	}
	return vec[r];
}

int nearestLarger(vector<int> vec, int val, int n){
	int l=0, r=n-1;
	while(l<r){
		int mid = (l+(r-l)/2);
		if(vec[mid]>val)
			r = mid-1;
		else if(vec[mid]<val)
			l = mid;
		else
			return val;
	}
	return vec[l];
}

int nearest(vector<int> vec, int n, int k){ //binary - error
	if(vec[0]>k)
		return vec[0];
	if(vec[n-1]<k)
		return vec[n-1];
	int ns = nearestSmaller(vec, k, n);
	int nl = nearestLarger(vec, k, n);
	cout<<ns<<" "<<nl<<endl;
	int minDiff = k-ns;
	int maxDiff = nl-k;
	if(minDiff<maxDiff)
		return ns;
	return nl; //minDiff>=maxDiff
}

/*
int nearest(vector<int> vec, int n, int k){ //linear
	int diff = INT_MAX;
	int ans = INT_MIN;
	for(int i=0; i<n; i++){
		int currDiff = abs(vec[i]-k);
		if(currDiff<diff){
			ans = vec[i];
			diff = currDiff;
		}else if(currDiff==diff){
			ans = vec[i]; //as it ll always be greater.
		}
	}
	return ans;
}
*/

int main(int argc, char const *argv[]) {
	int t;
	cin>>t;
	while(t-->0){
		int n, k;
		cin>>n>>k;
		vector<int> vec(n);
		for(int i=0; i<n; i++)
			cin>>vec[i];
		cout<<nearest(vec, n, k)<<endl;
	}
	return 0;
}