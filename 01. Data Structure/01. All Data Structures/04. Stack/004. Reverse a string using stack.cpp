#include<iostream>
#include<stack>

using namespace std;

string Reverse(string str){
  int n = str.length();
  stack<char> st;
  for(int i=0; i<n; i++){
    st.push(str[i]);
  }
  str = "";
  while(!st.empty()){
    str += st.top();
    st.pop();
  }
  str += '\0';
  return str;
}
int main(int argc, char const *argv[]) {
  string str;
  getline(cin, str);
  str = Reverse(str);
  cout<<str<<endl;
  return 0;
}