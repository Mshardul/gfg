#include<stack>

using namespace std;

void CheckParentheses(string s){
  bool ans=true;
  stack<char> st;
  for(char ch:s){
    if(ch=='(' || ch=='{' || ch=='[')
      st.push(ch);
    else if(ch==')'){
      if(st.empty() || st.top()!='('){
        ans = false;
        break;
      }
      st.pop();
    }else if(ch=='}'){
      if(st.empty() || st.top()!='{'){
        ans = false;
        break;
      }
      st.pop();
    }else if(ch==']'){
      if(st.empty() || st.top()!='['){
        ans = false;
        break;
      }
      st.pop();
    }
  }
  if(ans && st.empty())
    cout<<"balanced\n";
  else
    cout<<"not balanced\n";
}

int main(int argc, char const *argv[]) {
  int t;
  cin>>t;
  while(t-->0){
    string s;
    cin>>s;
    
    CheckParentheses(s);
  }
  return 0;
}