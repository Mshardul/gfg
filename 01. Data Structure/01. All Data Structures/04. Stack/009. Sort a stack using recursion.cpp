#include<iostream>
#include<stack>

using namespace std;

void Insert(stack<int> *st, int x){
  if(st->empty() || st->top()<x){
    st->push(x);
    return;
  }
  int temp =st->top();
  st->pop();
  Insert(st, x);
  st->push(temp);
}

void Sort(stack<int> *st){
  if(st->empty())
    return;
  int x = st->top();
  st->pop();
  Sort(st);
  Insert(st, x);
}

void Print(stack<int> st){
  while(!st.empty()){
    cout<<st.top()<<" ";
    st.pop();
  }
  cout<<endl;
}

int main(int argc, char const *argv[]) {
  int n, temp;
  cin>>n;
  
  stack<int> st;
  for(int i=0; i<n; i++){
    cin>>temp;
    st.push(temp);
  }
  
  Sort(&st);
  
  Print(st);
  return 0;
}