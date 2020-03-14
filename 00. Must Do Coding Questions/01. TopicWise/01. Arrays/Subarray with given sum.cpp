#include<iostream>
#include<vector>

using namespace std;

void GetSum(vector<int> vec, int n, int s){
  int sum = vec[0];
  int l = 0, r = 0, ans = 0;
  while(r<n){
    if(sum<s){
      sum += vec[++r];
    }else if(sum>s){
      sum -= vec[l++];
    }else{
      ans = 1;
      break;
    }
  }
  if(ans==1)
    cout<<l+1<<" "<<r+1<<endl;
  else
    cout<<"-1"<<endl;
}
int main(int argc, char const *argv[]) {
  int t;
  cin>>t;
  
  while(t-->0){
    int n, s;
    cin>>n;
    cin>>s;
    
    vector<int> vec(n);
    for(int i=0; i<n; i++)
      cin>>vec[i];
      
    GetSum(vec, n, s);
  }
  return 0;
}