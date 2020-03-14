#include<iostream>
#include<vector>
#include<iterator>

using namespace std;

void ReverseStr(string s){
  vector<string> ans;
  string temp = "";
  for(char ch:s){
    if(ch=='.'){
      ans.push_back(temp);
      temp="";
    }else{
      temp+=ch;
    }
  }
  cout<<temp;
  for(vector<string>::reverse_iterator iter=ans.rbegin(); iter!=ans.rend(); iter++)
    cout<<"."<<*iter;
  cout<<endl;
}

int main(int argc, char const *argv[]) {
  int t;
  cin>>t;
  while(t-->0){
    string s;
    cin>>s;
    
    ReverseStr(s);
  }
  return 0;
}