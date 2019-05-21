//dp - will solve later

#include<iostream>
#include<vector>

using namespace std;

void LenOfSuchLargestSubarray(vector<int> vec, int n){
  vector<int>vec ans(n);
  ans[0] = vec[0];
  if(vec[0]==0)
    ans[0]=vec[-1];
  for(int i=1; i<n; i++)
    if(vec[i]==1)
      ans[i]=1;
    else
      ans[i]=-1;
  
  //largest subarray with sum=0;
}
int main(int argc, char const *argv[]) {
  int t;
  cin>>t;
  while(t-->0){
    int n;
    cin>>n;
    
    vector<int> vec(n);
    
    for(int i=0; i<n; i++)
      cin>>vec[i];
    
    LenOfSuchLargestSubarray(vec, n);
  }
  return 0;
}