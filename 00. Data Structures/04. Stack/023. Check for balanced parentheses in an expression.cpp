// done in 02 > 04 > 057

//assumption: string consists of parantheses only.
#include<iostream>
#include<stack>

using namespace std;

bool CheckParentheses(string str){
  int n = str.length();
  stack<char> st;
  for(int i=0; i<n; i++){
    char ch = str[i];
    if(ch=='(' || ch=='{' || ch=='['){
      st.push(ch);
    }else if((ch==')' && st.top()=='(') || (ch=='}' && st.top()=='{') || (ch==']' && st.top()=='[')){
      st.pop();
    }else{
      return false;
    }
  }
  if(!st.empty())
    return false;
  return true;
}

int main(int argc, char const *argv[]) {
  string str;
  getline(cin, str);
  
  if(CheckParentheses(str)==true)
    cout<<"balanced parantheses";
  else
    cout<<"imbalanced parantheses";
  cout<<endl;
  return 0;
}