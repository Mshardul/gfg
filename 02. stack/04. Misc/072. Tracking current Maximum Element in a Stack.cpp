#include <iostream>
#include <stack>

using namespace std;

int main(int argc, char const *argv[]) {
  int n;
  cin>>n;
  
  stack<int> st;
  int maxEle=INT_MIN;
  int temp;
  
  for(int i=0; i<n; i++){
    cin>>temp;
    if(temp>maxEle)
      maxEle=temp;
    st.push(maxEle);
  }
  
  for(int i=0; i<n; i++){
    cout<<"max = "<<st.top()<<endl;
    st.pop();
  }
  
  return 0;
}