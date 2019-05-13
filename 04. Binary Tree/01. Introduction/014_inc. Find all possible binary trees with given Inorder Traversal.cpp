#include<iostream>
#include<vector>

using namespace std;
//just calculating catalan number

vector<int> cat(1000); //assuming n<1000

int CatalanNum(int n){
  if(n<=1)
    return 1;
    
  int res = 0;
  int l, r;
  
  cat[0] = 1;
  cat[1] = 1;
  
  for(int i=0; i<n; i++){
    if(cat[i]==0)
      cat[i] = CatalanNum(i);
    if(cat[n-i]==0)
      cat[n-i-1] = CatalanNum(n-i-1);
    res += cat[i]*cat[n-i-1];
  }
  
  return res;
}

int main(int argc, char const *argv[]) {
  int n;
  cin>>n;
  
  // vector<int> in(n);
  // for(int i=0; i<n; i++)
  //   cin>>in[i];
  
  for(int i=0; i<=n; i++)
    cat[i] = 0;
    
  int res = CatalanNum(n);
  cout<<res<<endl;
  
  return 0;
}