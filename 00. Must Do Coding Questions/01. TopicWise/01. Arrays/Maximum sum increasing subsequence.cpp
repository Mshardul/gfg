//similar to LIS problem

#include<iostream>
#include<vector>
#include<stack>

using namespace std;

void PrintAns(vector<int> vec){
  for(vector<int>::iterator iter=vec.begin(); iter!=vec.end(); iter++)
    cout<<*iter<<" ";
  cout<<endl;
}

void GetMaxSumIncSubsequence(vector<int> vec, int n){
  vector<int> ans(n);
  for(int i=0; i<n; i++)
    ans[i] = vec[i];
  for(int i=1; i<n; i++){
    for(int j=0; j<i; j++){ //'j' loop tells if we need to add 'ith' element to the sum till now.
      if(vec[i]>vec[j] && ans[i]<ans[j]+vec[i])
        ans[i] = ans[j]+vec[i];
    }
    // cout<<i<<": ";
    // PrintAns(ans);
  }
  int max = ans[0];
  for(int i=1; i<n; i++){
    if(max<ans[i])
      max = ans[i];
  }
  cout<<max<<endl;
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
      
    GetMaxSumIncSubsequence(vec, n);
  }
  return 0;
}