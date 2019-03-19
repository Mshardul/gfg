#include<iostream>
#include<stack>
#include<queue>

using namespace std;

int main(int argc, char const *argv[]) {
  int n, k, temp;
  cin>>n;
  
  stack<int> st;
  queue<int> q;
  
  for(int i=0; i<n; i++){
    cin>>temp;
    q.push(temp);
  }
  
  cin>>k;
  
  int i=0;
  while(i<k){
    st.push(q.front());
    q.pop();
    i++;
  }
  while(!st.empty()){
    q.push(st.top());
    st.pop();
  }
  while(i<n){
    q.push(q.front());
    q.pop();
    i++;
  }
  
  while(!q.empty()){
    cout<<q.front()<<" ";
    q.pop();
  }
  cout<<endl;
  
  return 0;
}