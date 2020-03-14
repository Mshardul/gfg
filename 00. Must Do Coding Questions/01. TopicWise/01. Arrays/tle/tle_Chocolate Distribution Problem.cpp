//constraints: t(100), n(10^7) -> so, should be linear

#include<iostream>
#include<vector>

using namespace std;

void DistributeChocolates(vector<int> vec, int n, int m){
  sort(vec.begin(), vec.end());
  int diff = vec[m-1]-vec[0];
  int min = diff;
  for(int i=m; i<n; i++){
    diff = vec[i] - vec[i-(m-1)];
    if(diff<min)
      min=diff;
  }
  cout<<min<<endl;
}

int main(int argc, char const *argv[]) {
  int t;
  cin>>t;
  
  while(t-->0){
    int n, m;
    cin>>n;
    
    vector<int> vec(n);
    
    for(int i=0; i<n; i++)
      cin>>vec[i];
      
    cin>>m;
    
    DistributeChocolates(vec, n, m);
  }
  return 0;
}