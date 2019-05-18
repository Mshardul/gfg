#include<iostream>

using namespace std;

void GetKthSmallestEle(vector<int> vec, int n, int k){
  int grp = n/5;
  vector<int> median;
  for(int i=0; i<grp; i++){
    int a = 
  }
}
int main(int argc, char const *argv[]) {
  int t;
  cin>>t;
  
  while(t-->0){
    int n, k;
    cin>>n;
  
    vector<int> vec(n);
    for(int i=0; i<n; i++)
      cin>>vec[i];
    
    cin>>k
    
    GetKthSmallestEle(vec, n, k);
  }
  return 0;
}