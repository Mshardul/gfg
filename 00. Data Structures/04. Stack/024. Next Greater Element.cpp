#include<iostream>
#include<vector>
#include<stack>

using namespace std;

void GetNGE(vector<int> vec, int n){
  stack<int> st;
  vector<int> nge(n);
  for(int i=0; i<n; i++)
    nge[i] = -1;
    
  st.push(0);
  
  for(int i=1; i<n; i++){
    while(!st.empty() && vec[st.top()]<vec[i]){
      nge[st.top()] = vec[i];
      st.pop();
    }
    st.push(i);
  }
  
  for(int i=0; i<n; i++)
    cout<<vec[i]<<"\t"<<nge[i]<<endl;
}

int main(int argc, char const *argv[]) {
  int n;
  cin>>n;
  
  vector<int> vec(n);
  for(int i=0; i<n; i++)
    cin>>vec[i];
    
  GetNGE(vec, n);
  return 0;
}