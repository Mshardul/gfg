#include<iostream>

using namespace std;

bool CheckSubstr(string s, string x, int l){
  int n = s.length();
  int m = x.length();
  if(n-l<m)
    return false;
  for(int i=0; i<m; i++){
    if(s[l+i]!=x[i])
      return false;
  }
  return true;
}

int StrStr(string s, string x){
  int n = s.length();
  int m = x.length();
  
  if(n<m)
    return -1;
  
  int intX = 0;
  int intS = 0;
  
  for(int i=0; i<m; i++){
    intX += (x[i]-'A')+1;
    intS += (s[i]-'A')+1;
  }
  if(intX==intS && CheckSubstr(s, x, 0))
    return 0;
  for(int i=m; i<n; i++){
    intS = intS + (s[i]-'a'+1) - (s[i-m]-'a'+1);
    if(intS==intX && CheckSubstr(s, x, i-m+1))
      return (i-m+1);
  }
  return -1;
}

int main(int argc, char const *argv[]) {
  int t;
  cin>>t;
  while(t-->0){
    string s, x;
    cin>>s>>x;
    
    cout<<StrStr(s, x)<<endl;
  }
  return 0;
}