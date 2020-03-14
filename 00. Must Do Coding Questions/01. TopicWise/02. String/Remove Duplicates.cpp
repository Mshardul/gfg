#include<iostream>
#include<vector>

using namespace std;

void RemoveDup(string s){
  vector<bool> vec(256);
  int n = s.length();
  char ch;
  for(char ch:s){
    if(vec[int(ch)]==false){
      cout<<ch;
      vec[int(ch)]=true;
    }
  }
  cout<<endl;
}
int main(int argc, char const *argv[]) {
  int t;
  cin>>t;
  cin.ignore(); //deletes the newline buffer
  while(t-->0){
    string s;
    getline(cin, s);
    RemoveDup(s);
  }
  return 0;
}