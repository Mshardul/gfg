#include<iostream>
#include<vector>

using namespace std;

bool CheckAnagram(string a, string b){
  int n = a.length();
  
  vector<long> vecA(26);
  vector<long> vecB(26);
  
  if(b.length()!=n)
    return false;
  for(int i=0; i<n; i++){
    vecA[(a[i]-'a')]++;
    vecB[(b[i]-'a')]++;
  }
  
  for(int i=0; i<26; i++){
    if(vecA[i]!=vecB[i])
      return false;
  }
  return true;
}

int main(int argc, char const *argv[]) {
  int t;
  cin>>t;
  
  while(t-->0){
    string a, b;
    cin>>a>>b;
    
    if(CheckAnagram(a, b))
      cout<<"YES\n";
    else
      cout<<"NO\n";
  }
  return 0;
}