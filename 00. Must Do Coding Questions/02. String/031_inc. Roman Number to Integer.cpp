//not sure how the conversion works

#include<iostream>
using namespace std;

int convert(char ch){
  int ans = 0;
  switch(ch){
    case 'I': ans = 1; break;
    case 'V': ans = 5; break;
    case 'X': ans = 10; break;
    case 'L': ans = 50; break;
    case 'C': ans = 100; break;
    case 'D': ans = 500; break;
    case 'M': ans = 1000; break;
  }
  return ans;
}

int ToInt(string s){
  if(s.length()==0)
    return 0;
  
  char prev = s[0];
  int intPrev = convert(s[0]);
  
  int ans = convert(s[0]);
  int intCurr;
  
  for(int i=1; i<s.length(); i++){
    intCurr = convert(s[i]);
    if(intPrev>=intCurr)
      ans += intCurr;
    else
      ans = intCurr - ans;
    intPrev = intCurr;
  }
  
  return ans;
}

int main(int argc, char const *argv[]) {
  int t;
  cin>>t;
  
  while(t-->0){
    string s;
    cin>>s;
    
    cout<<ToInt(s)<<endl;
  }
  return 0;
}