#include<iostream>
#include<vector>

using namespace std;

void LongestDistinctCharString(string s){
  vector<int> vec(26);
  
  for(int i=0; i<26; i++)
    vec[i] = -1;
    
  int i=0;
  int max = 0, tempLen = 0;
  for(char ch: s){
    int alphaNum = ch-'a';
    if(vec[alphaNum]==-1){
      vec[alphaNum] = i;
      tempLen++;
    }else{
      tempLen = min(tempLen+1, i-vec[alphaNum]);
      vec[alphaNum] = i;
    }
    // cout<<ch<<" "<<tempLen<<" "<<max<<endl;
    if(tempLen>max)
      max = tempLen;
    i++;
  }
  cout<<max<<endl;
}
int main(int argc, char const *argv[]) {
  int t;
  cin>>t;
  while(t-->0){
    string s;
    cin>>s;
    
    LongestDistinctCharString(s);
  }
  return 0;
}