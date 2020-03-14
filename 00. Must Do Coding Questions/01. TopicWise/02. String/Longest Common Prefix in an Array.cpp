#include<iostream>
#include<queue>

using namespace std;

void Print(deque<string> d){
  while(!d.empty()){
    cout<<d.front()<<" ";
    d.pop_front();
  }
  cout<<endl;
}

void LongestCommonPrefix(deque<string> *d){
  // Print(*d);
  if(d->size()==1)
    return;
  string a = d->front();
  d->pop_front();
  string b = d->front();
  d->pop_front();
  
  int n = min(a.size(), b.size());
  
  string temp = "";
  for(int i=0; i<n; i++){
    if(a[i]==b[i])
      temp += a[i];
    else
      break;
  }
  
  d->push_back(temp);
  if(temp.length()==0)
    return;
  return LongestCommonPrefix(d);
}

int main(int argc, char const *argv[]) {
  int t;
  cin>>t;
  
  while(t-->0){
    int n;
    cin>>n;
    
    deque<string> d;
    string s;
    for(int i=0; i<n; i++){
      cin>>s;
      d.push_back(s);
    }
    
    LongestCommonPrefix(&d);
    if(d.size()==1)
      cout<<d.front()<<endl;
    else
      cout<<"-1"<<endl;
  }
  return 0;
}