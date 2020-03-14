#include<iostream>
#include<vector>

using namespace std;

void RelativeSorting(vector<int> a, int n, vector<int> b, int m){
  
}
int main(int argc, char const *argv[]) {
  int t;
  cin>>t;
  
  while(t-->0){
    int n, m;
    cin>>n>>m;
    
    vector<int> a(n);
    vector<int> b(m);
    
    for(int i=0; i<n; i++)
      cin>>a[i];
      
    for(int i=0; i<m; i++)
      cin>>b[i];
    
    RelativeSorting(a, n, b, m);
  }
  return 0;
}