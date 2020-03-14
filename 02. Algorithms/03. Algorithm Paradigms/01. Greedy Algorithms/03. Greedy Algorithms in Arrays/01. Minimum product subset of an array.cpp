#include<iostream>
#include<vector>

using namespace std;

int minProd(vector<int> vec){ //not sure if it ll work
	int n = vec.size();
	sort(vec.begin(), vec.end());
	int mn = vec[0];
	int mx = vec[0];
	bool isZero = false;
	for(int i=1; i<n; i++){
		if(vec[i]==0){
			isZero = true;
			continue;
		}
		mn = min(vec[i], min(mn*vec[i], mx*vec[i]));
		mx = max(vec[i], max(mx*vec[i], mx*vec[i]));
		cout<<i<<" "<<mn<<" "<<mx<<endl;
	}
	if(isZero)
		return mn;
	return min(mn, 0);
}

int minProd(vector<int> vec){ //should work
	int n = vec.size();
	sort(vec.begin(), vec.end());
	int mn = vec[0];
	int mx = vec[0];
	bool isZero = false;
	int minPos = INT_MAX;
	int maxNeg = INT_MIN;
	int prodNeg = 1;
	for(int i=0; i<n; i++){
		if(vec[i]==0){
			isZero = true;
			continue;
		}
		if(vec[i]>0){
			if(vec[i]<minPos)
				minPos = vec[i];
		}else{
			if(vec[i]>maxNeg)
				maxNeg = vec[i];
			prodNeg *= vec[i];
		}
	}
	
	if(prodNeg<0){
		return prodNeg;
	}else if(maxNeg!=INT_MIN){
		return prodNeg/maxNeg;
	}
	
	if(isZero)
		return 0;
		
	return minPos;
}

int main(int argc, char const *argv[]) {
	int n;
	cin>>n;
	vector<int> vec(n);
	for(int i=0; i<n; i++)
		cin>>vec[i];
	cout<<minProd(vec)<<endl;
	return 0;
}