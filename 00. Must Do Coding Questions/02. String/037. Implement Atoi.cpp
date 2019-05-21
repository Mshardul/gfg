#include<iostream>

using namespace std;

int AToI(string s){
  int ans = 0;
  int ind = 0;
  int n = s.length();
  if(s[0]=='-')
    ind = 1;
  char ch;
  while(ind<n){
    ch = s[ind];
    if(!(ch>='0' && ch<='9'))
      return -1;
    ans = (ans*10)+(ch-'0');
    ind++;
  }
  if(s[0]=='-')
    return 0-ans;
  return ans;
}
int main(int argc, char const *argv[]) {
  int t;
  cin>>t;
  
  while(t-->0){
    string s;
    cin>>s;
    
    cout<<AToI(s)<<endl;
  }
  return 0;
}