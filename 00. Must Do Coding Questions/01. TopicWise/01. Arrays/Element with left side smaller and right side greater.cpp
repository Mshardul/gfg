#include<iostream>
#include<vector>
#include<deque>

using namespace std;

void GetEle(vector<int> vec, int n){
  vector<int> max(n);
  vector<int> min(n);
  
  max[0] = 0;
  min[0] = n-1;
  
  for(int i=1; i<n; i++){
    if(vec[i]>vec[max[i-1]])
      max[i] = i;
    else
      max[i] = max[i-1];
      
    if(vec[n-1-i]<vec[min[i-1]])
      min[i] = n-1-i;
    else
      min[i] = min[i-1];
  }
    
  int ans = -1;
  for(int i=1; i<n-1; i++){
    if(vec[max[i-1]]<=vec[i] && vec[i]<=vec[min[n-1-i]]){
      ans = vec[i];
      break;
    }
  }
  cout<<ans<<endl;
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
    
    GetEle(vec, n);
  }
  return 0;
}