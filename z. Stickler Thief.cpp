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

int notAdj(vector<int> vec, int n){
  vector<int> dp(n);
	if(n==0)
		return 0;
	if(n==1)
    return vec[0];
  if(n==2)
    return max(vec[0], vec[1]);
  dp[0] = vec[0];
  dp[1] = max(vec[0], vec[1]);
  dp[2] = vec[2]+vec[0];
  int mx = max(dp[2], dp[1]);
  for(int i=3; i<n; i++){
		dp[i] = vec[i]+max(dp[i-2], dp[i-3]);
		mx = max(mx, dp[i]);
  }
	return mx;
}

int main()
{
	int t;
  cin>>t;
  while(t-->0){
  	int n;
    cin>>n;
    vector<int> vec(n);
    for(int i=0; i<n; i++)
      cin>>vec[i];
    cout<<notAdj(vec, n)<<endl;
  }
}