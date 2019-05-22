#include<iostream>
#include<vector>

using namespace std;

string RemoveSpc(string s){
  string ret = "";
  for(char ch:s){
    if(ch>='a' && ch<='z')
      ret += ch;
  }
  return ret;
}

void GetChar(string s, int n){
  s = RemoveSpc(s);
  
  vector<int> vec(26);
  
  int ind = -1;
  char uniq = '!';
  char ch;
  for(int i=0; i<n; i++){
    ch = s[i];
    if(vec[ch-'a']==0)
      vec[ch-'a'] = 1;
    else if(vec[ch-'a']==1)
      vec[ch-'a'] = 2;
      
    // cout<<endl<<"-->"<<uniq<<" "<<ch<<" "<<ind<<" "<<i<<endl;
    if(uniq=='!' || uniq==ch){
      ind++;
      while(ind<=i){
        if(vec[s[ind]-'a']==1){
          uniq = s[ind];
          vec[s[ind]-'a']=2;
          // cout<<"found unique @ "<<i<<endl;
          break;
        }
        ind++;
      }
      if(ind>i){
        cout<<"-1 ";
        ind--;
        uniq = '!';
      }else{
        cout<<uniq<<" ";
      }
    }else{
      cout<<uniq<<" ";
    }
  }
  cout<<endl;
}

int main(int argc, char const *argv[]) {
  int t;
  cin>>t;
  
  while(t-->0){
    int n;
    cin>>n;
    cin.ignore(); //deletes the newline buffer
    string s;
    getline(cin, s);
    GetChar(s, n);
  }
  return 0;
}