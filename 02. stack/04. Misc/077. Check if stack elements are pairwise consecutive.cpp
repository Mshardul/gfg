#include<iostream>
#include<stack>

using namespace std;

int main(int argc, char const *argv[]) {
  bool ans=true;
  
  int n;
  cin>>n;
  
  stack<int> st;
  
  int temp;
  for(int i=0; i<n; i++){
    cin>>temp;
    st.push(temp);
  }
    
  if(n%2!=0)
    st.pop();
  while(!st.empty()){
    temp=st.top();
    st.pop();
    if(temp==st.top()+1 || temp==st.top()-1)
      st.pop();
    else{
      ans=false;
      break;
    }
  }
  
  cout<<ans<<endl;
  
  return 0;
}