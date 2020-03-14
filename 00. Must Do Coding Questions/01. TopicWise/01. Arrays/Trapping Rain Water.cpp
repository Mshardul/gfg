#include<iostream>
#include<vector>

using namespace std;

int TrapWater(vector<int> vec, int n){
  vector<int> left(n);
  left[0] = vec[0];
  for(int i=1; i<n; i++)
    left[i] = max(left[i-1], vec[i]);
  
  vector<int> right(n);
  right[n-1] = vec[n-1];
  for(int i=n-2; i>=0; i--)
    right[i] = max(right[i+1], vec[i]);
    
  int ans = 0;
  for(int i=0; i<n; i++)
    ans += (min(left[i], right[i])-vec[i]);
  
  return ans;
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
    
    cout<<TrapWater(vec, n)<<endl;
  }
  return 0;
}