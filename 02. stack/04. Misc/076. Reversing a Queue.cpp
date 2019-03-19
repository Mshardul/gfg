#include<iostream>
#include<stack>
#include<queue>

using namespace std;

int main(int argc, char const *argv[]) {
  int n;
  cin>>n;
  
  int temp;
  
  queue<int> q;
  for(int i=0; i<n; i++){
    cin>>temp;
    q.push(temp);
  }
    
  stack<int> st;
  while(!q.empty()){
    st.push(q.front());
    q.pop();
  }
  
  while(!st.empty()){
    q.push(st.top());
    st.pop();
  }
  
  while(!q.empty()){
    cout<<q.front()<<" ";
    q.pop();
  }
  cout<<endl;
  
  return 0;
}