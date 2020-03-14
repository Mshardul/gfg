#include<iostream>
#include<stack>

using namespace std;

int main(int argc, char const *argv[]) {
  int n;
  cin>>n;
  
  stack<int> st;
  while(n!=0){
    st.push(n%10);
    n/=10;
  }
  
  int i=1;
  while(!st.empty()){
    n+=(st.top()*i);
    i*=10;
    st.pop();
  }
  
  cout<<n<<endl;
  
  return 0;
}