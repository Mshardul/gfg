#include<iostream>
#include<stack>

using namespace std;

int main(int argc, char const *argv[]) {
  int n;
  cin>>n;
  
  int max=INT_MIN;
  
  int diff;
  
  char temp;
  
  stack<int> st;
  for(int i=0; i<n; i++){
    cin>>temp;
    if(temp=='('){
      st.push(i);
    }
    else{
      if(!st.empty()){
        diff=i-st.top()+1;
        st.pop();
        if(max<diff)
          max=diff;
      }
    }
  }
  
  cout<<max;
  return 0;
}