#include<iostream>
#include<vector>

using namespace std;

void Print2D(vector<vector<int> > res){
	vector<vector<int> >::iterator iter = res.begin();
	while(iter!=res.end()){
		vector<int>::iterator iter2 = iter->begin();
		while(iter2!=iter->end()){
			cout<<*iter2<<" ";
			iter2++;
		}
		cout<<endl;
		iter++;
	}
}

int coins(vector<int> vec, int sum){
	int n = vec.size();
	
	vector<vector<int> > dp;
	dp.resize(n, vector<int>(sum+1));
	
	for(int i=0; i<n; i++)
		dp[i][0] = 1; //no coins - forming every sum
	
	int inclJ, exclJ;
	for(int i=0; i<n; i++){
		for(int j=1; j<=sum; j++){
			if(j>= vec[i]){
				inclJ = dp[i][j-vec[i]];
			}else{
				inclJ = 0;
			}
				
			exclJ = dp[i][j-1]+1;
			dp[i][j] = inclJ+exclJ;
		}
	}
	Print2D(dp);
	return dp[n-1][sum];
}

int main(int argc, char const *argv[]) {
	int n;
	cin>>n;
	
	vector<int> vec(n);
	
	for(int i=0; i<n; i++)
		cin>>vec[i];
	
	int sum;
	cin>>sum;
	
	cout<<coins(vec, sum)<<endl;
	return 0;
}