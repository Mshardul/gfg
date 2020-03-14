//"abba": ""
//"aabba": "a"


#include<iostream>
#include<vector>

using namespace std;

int GetNextInd(string s, int i){
  // cout<<"next index for "<<i<<" is ";
  char ch;
  while(((ch=s[i])!='\0') && s[i]==s[i+1])
    i++;
  // cout<<i+1<<endl;
  return i+1;
}

string RemoveDup(string s){
  bool reattempt = false;
  int i=0;
  string ans;
  char ch;
  if(s.length()==1 || s[0]!=s[1]){
    ans+=s[0];
    i++;
  }
  while((ch=s[i])!='\0'){
    int next = GetNextInd(s, i);
    if(next-i>1)
      reattempt = true;
    else
      ans += s[i];
    i = next;
  }
  if(reattempt){
    // cout<<ans<<endl;
    return RemoveDup(ans);
  }
  return ans;
}

int main(int argc, char const *argv[]) {
  int t;
  cin>>t;
  
  while(t-->0){
    string s;
    cin>>s;
    string ans = RemoveDup(s);
    cout<<ans<<endl;
  }
  return 0;
}