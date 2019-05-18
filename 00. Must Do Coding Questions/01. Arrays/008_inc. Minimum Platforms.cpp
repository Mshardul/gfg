#include<iostream>
#include<vector>

using namespace std;

int main(int argc, char const *argv[]) {
  int t;
  cin>>t;
  
  while(t-->0){
    int n;
    cin>>n;
    
    vector<int> a(n);
    vector<int> d(n);
    
    for(int i=0; i<n; i++)
      cin>>a[i];
      
    for(int i=0; i<n; i++)
      cin>>d[i];
  }
  return 0;
}