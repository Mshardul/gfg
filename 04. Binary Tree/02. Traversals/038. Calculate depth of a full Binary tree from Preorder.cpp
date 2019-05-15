#include<iostream>

using namespace std;

int GetDepth(string str){
  int depth = 0;
  if(str[0]=='l')
    return 0;
  int nNodesNow = 1;
  int nNodesNext = 0;
  int n = str.length();
  int ind = 1;
  while(nNodesNow!=0){
    nNodesNext = 0;
    for(int i=0; i<2*nNodesNow; i++){
      if(str[ind]=='n')
        nNodesNext++;
      ind++;
    }
    depth++;
    nNodesNow = nNodesNext;
  }
  return depth;
}

int main(int argc, char const *argv[]) {
  string str;
  cin>>str;
  
  int d = GetDepth(str);
  cout<<d<<endl;
  
  return 0;
}