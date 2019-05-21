#include<iostream>
#include <vector>

using namespace std;

void GetPermutations(string s, int l, int r, vector<string> *ans){
  if(l==r){
    ans->push_back(s);
    return;
  }
  char temp;
  for(int i=l; i<=r; i++){
    temp = s[i];
    s[i] = s[l];
    s[l] = temp;
    
    GetPermutations(s, l+1, r, ans);
    
    temp = s[i];
    s[i] = s[l];
    s[l] = temp;
  }
}

int main(int argc, char const *argv[]) {
  int t;
  cin>>t;
  while(t-->0){
    string s;
    cin>>s;
    
    vector<string> ans;
    GetPermutations(s, 0, s.length()-1, &ans);
    
    sort(ans.begin(), ans.end());
    
    for(vector<string>::iterator iter=ans.begin(); iter!=ans.end(); iter++)
      cout<<*iter<<" ";
    cout<<endl;
  }
  return 0;
}