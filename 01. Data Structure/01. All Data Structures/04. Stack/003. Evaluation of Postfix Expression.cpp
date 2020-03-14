// done in 02 > 02 > 027

#include<iostream>
#include<stack>
#include<vector>

using namespace std;

void Evaluate(vector<char> vec, int n){ //assuming single digit numbers;
  stack<int> st;
  for(int i=0; i<n; i++){
    char ch = vec[i];
    if(ch=='+' || ch=='-' || ch=='*' || ch=='/'){
      int second = st.top();
      st.pop();
      int first = st.top();
      st.pop();
      switch (ch) {
        case '+': st.push(first+second); break;
        case '-': st.push(first-second); break;
        case '*': st.push(first*second); break;
        case '/': st.push(first/second);
      }
    }else{
      st.push(ch-'0');
    }
  }
  cout<<st.top()<<endl;
}

int main(int argc, char const *argv[]) {
  int n;
  cin>>n;
  
  vector<char> vec(n);
  for(int i=0; i<n; i++)
    cin>>vec[i];
  
  Evaluate(vec, n);  
  return 0;
}