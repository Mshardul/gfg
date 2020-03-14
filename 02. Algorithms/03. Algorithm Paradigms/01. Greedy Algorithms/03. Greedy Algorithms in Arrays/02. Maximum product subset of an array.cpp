#include<iostream>
#include<vector>

using namespace std;

int maxProdSubset(vector<int> vec){ //should work
	int n = vec.size();
	bool isZero = false;
	int posProd = 0;
	int negProd = 0;
	int maxNeg = INT_MIN;
	for(int i=0; i<n; i++){
		if(vec[i]==0){
			isZero = true;
			continue;
		}
		if(vec[i]>0){
			if(posProd==0)
				posProd = 1;
			posProd *= vec[i];
		}else{
			if(negProd==0)
				negProd = 1;
			negProd *= vec[i];
			if(vec[i]>maxNeg)
				maxNeg = vec[i];
		}
	}
	
	int ans = 0;
	if(negProd>1)
		ans = negProd;
	if(negProd<0)
		ans = negProd/maxProd;
	
	if(posProd!=0 && ans!=0)
		return ans*posProd;

	return 0;
}
int main(int argc, char const *argv[]) {
	int n;
	cin>>n;
	vector<int> vec(n);
	for(int i=0; i<n; i++)
		cin>>vec[i];
	cout<<maxProdSubset(vec)<<endl;
	return 0;
}