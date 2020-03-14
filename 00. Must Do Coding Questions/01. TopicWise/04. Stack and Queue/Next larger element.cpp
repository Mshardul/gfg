#include <iostream>
#include<vector>
#include<stack>
using namespace std;

void NLE(vector<long> vec, int n){
  stack<int> st;
  vector<int> ans(n);
  st.push(0);
  for(int i=1; i<n; i++){
    while(!st.empty() && vec[st.top()]<vec[i]){
      ans[st.top()] = i;
      st.pop();
    }
    st.push(i);
  }
  while(!st.empty()){
    ans[st.top()]=-1;
    st.pop();
  }
  for(int i=0; i<n; i++){
    if(ans[i]==-1)
      cout<<"-1";
    else
      cout<<vec[ans[i]];
    cout<<" ";
  }
  cout<<endl;
}

int main(int argc, char const *argv[]) {
  int t;
  cin>>t;
  while(t-->0){
    int n, temp;
    cin>>n;
    
    vector<long> vec(n);
    
    for(int i=0; i<n; i++)
      cin>>vec[i];
    
    NLE(vec, n);
  }
  return 0;
}