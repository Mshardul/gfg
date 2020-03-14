#include <iostream>
#include <stack>
#include <queue>

using namespace std;

int main(int argc, char const *argv[]) {
  int n;
  cin>>n;

  int temp;
  queue<int> q;
  stack<int> st;
  for(int i=0; i<n; i++){
    cin>>temp;
    q.push(temp);
  }
  
  cout<<"got q\n";
  for(int i=0; i<n; i++){
    cin>>temp;
    while (!q.empty() && q.front()!=temp) {
      if(!st.empty() && st.top()==temp)
        break;
      else{
        st.push(q.front());
        q.pop();
      }
    }
    // cout<<"out of while\n";
    if(!st.empty() && st.top()==temp){
      cout<<temp<<" found in stack\n";
      st.pop();
    }
    else if(!q.empty() && q.front()==temp){
      cout<<temp<<" found in queue\n";
      q.pop();
    }
    else{
      cout<<temp<<" not found anywhere\n";
      break;
    }
  }
  cout<<endl;
  return 0;
}