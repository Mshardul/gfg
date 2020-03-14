#include<iostream>

using namespace std;

int LastInd(string s){
  int n = s.length();
  for(int i=n-1; i>-1; i--){
    if(s[i]=='1')
      return i;
  }
  return -1;
}
int main(int argc, char const *argv[]) {
  int t;
  cin>>t;
  while(t-->0){
    string s;
    cin>>s;
    cout<<LastInd(s)<<endl;
  }
  return 0;
}