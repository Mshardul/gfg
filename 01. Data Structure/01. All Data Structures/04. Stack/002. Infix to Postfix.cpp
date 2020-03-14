// done in 02 > 02 > 013

#include<iostream>
#include<stack>
#include<vector>

using namespace std;

void InToPost(vector<char> vec, int n){
  stack<char> st;
  for(int i=0; i<n; i++){
    char ch=vec[i];
    if(ch=='('){
      st.push(ch);
    }else if(ch==')'){
      while(st.top()!='('){
        cout<<st.top()<<" ";
        st.pop();
      }
      st.pop();
    }else if(ch=='+' or ch=='-'){
      while (!st.empty() && st.top()!='(') {
        cout<<st.top()<<" ";
        st.pop();
      }
      st.push(ch);
    }else if(ch=='*' or ch=='/'){
      while(!(st.empty()) && (st.top()=='*' || st.top()=='/') && st.top()!='('){
        cout<<st.top()<<" ";
        st.pop();
      }
      st.push(ch);
    }else if(ch=='\0'){
      while (!st.empty()) {
        cout<<st.top()<<" ";
        st.pop();
      }
    }else{
      cout<<ch<<" ";
    }
  }
  while(!st.empty()){
    cout<<st.top()<<" ";
    st.pop();
  }
  cout<<endl<<"done\n";
}

int main(int argc, char const *argv[]) {
  int n;
  cin>>n;
  
  vector<char> vec(n);
  for(int i=0; i<n; i++)
    cin>>vec[i];
    
  InToPost(vec, n);
  return 0;
}