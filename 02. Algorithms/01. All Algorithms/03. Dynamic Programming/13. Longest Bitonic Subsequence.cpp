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

int lbs(vector<int> vec, int n){
	vector<int> dpInc(n); //lis from l to r
	for(int i=0; i<n; i++){
		int ans = 0;
		for(int j=i-1; j>-1; j--){
			if(vec[j]<vec[i] && dpInc[j]>ans)
				ans = dpInc[j];
		}
		dpInc[i] = ans+1;
	}
	
	vector<int> dpDec(n); //lds from r to l
	for(int i=n-1; i>-1; i--){
		int ans = 0;
		for(int j=i+1; j<n; j++){
			if(vec[j]<vec[i] && dpDec[j]>ans)
				ans = dpDec[j];
		}
		dpDec[i] = ans+1;
	}
	
	Print(dpInc);
	Print(dpDec);
	
	int ret = 1;
	for(int i=0; i<n; i++)
		ret = max(ret, dpInc[i]+dpDec[i]-1);
	return ret;
}

int main(int argc, char const *argv[]) {
	int n;
	cin>>n;
	vector<int> vec(n);
	for(int i=0; i<n; i++)
		cin>>vec[i];
	
	cout<<lbs(vec, n)<<endl;
	return 0;
}