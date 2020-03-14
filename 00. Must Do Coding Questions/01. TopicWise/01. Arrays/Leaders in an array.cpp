#include<iostream>
#include<vector>
#include<stack>

using namespace std;

void GetLeader(vector<int> vec, int n){
  vector<int> ans;
  stack<int> st;
  st.push(vec[--n]);
  ans.push_back(st.top());
  while(--n>=0){
    while(!st.empty() && st.top()<=vec[n])
      st.pop();
    if(st.empty())
      ans.push_back(vec[n]);
    st.push(vec[n]);
  }
  for(vector<int>::reverse_iterator iter=ans.rbegin(); iter!=ans.rend(); iter++)
    cout<<*iter<<" ";
  cout<<endl;
}

int main(int argc, char const *argv[]) {
  int t;
  cin>>t;
  
  while (t-->0) {
    int n;
    cin>>n;
    
    vector<int> vec(n);
    for(int i=0; i<n; i++)
      cin>>vec[i];
      
    GetLeader(vec, n);
  }
  return 0;
}