#include<iostream>
#include<stack>
#include<vector>

using namespace std;

void GetStockSpan(vector<int> vec, int n){
  vector<int> ans(n); 
  for(int i=0; i<n; i++)
    ans[i] = i+1;
    
  stack<int> st;
  st.push(0);
  
  for(int i=1; i<n; i++){
    while(!st.empty() && vec[st.top()]<vec[i]){
      st.pop();
    }
    if(!st.empty())
      ans[i] = i-st.top();
    st.push(i);
  }
  
  for(int i=0; i<n; i++)
    cout<<ans[i]<<" ";
  cout<<endl;
}

int main(int argc, char const *argv[]) {
  int n;
  cin>>n;
  
  vector<int> vec(n);
  for(int i=0; i<n; i++)
    cin>>vec[i];
    
  GetStockSpan(vec, n);
  return 0;
}