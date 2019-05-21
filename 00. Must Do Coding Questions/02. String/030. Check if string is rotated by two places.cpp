#include<iostream>

using namespace std;

int CheckLeftRotated(string a, string b){
  int n = a.length();
  if(b.length()!=n)
    return 0;
    
  if(n<2){
    if(a==b) return 1;
    return 0;
  }
    
  for(int i=0; i<n-2; i++){
    if(a[i]!=b[i+2])
      return 0;
  }
  for(int i=0; i<2; i++){
    if(b[i]!=a[n-2+i])
      return 0;
  }
  return 1;
}

int main(int argc, char const *argv[]) {
  int t;
  cin>>t;
  while(t-->0){
    string a, b;
    cin>>a;
    cin>>b;
    
    int ans = CheckLeftRotated(a,b) + CheckLeftRotated(b, a);
    if(ans)
      cout<<"1";
    else
      cout<<"0";
    
    cout<<endl;
  }
  return 0;
}