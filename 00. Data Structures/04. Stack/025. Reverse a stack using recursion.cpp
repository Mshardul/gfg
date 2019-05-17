#include<iostream>
#include<stack>

using namespace std;

void PushAtBottom(stack<int> *st, int x){
  if(st->empty())
    st->push(x);
  int temp = st.top();
  st.pop();
  PushAtBottom(st, temp);
  st->push(x);
}
void Reverse(stack<int> *st){
  if(st->empty())
    return;
  int val = st->top();
  st->pop();
  Reverse(st);
  PushAtBottom(st, val);
  cout<<"inserted "<<val<<endl;
}

int main(int argc, char const *argv[]) {
  int n, temp;
  cin>>n;
  
  stack<int> st;
  for(int i=0; i<n; i++){
    cin>>temp;
    st.push(temp);
  }
  
  Reverse(&st);
  
  while(!st.empty()){
    cout<<st.top()<<" ";
    st.pop();
  }
  cout<<endl;
  
  return 0;
}