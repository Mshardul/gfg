#include <iostream>
#include <stack>
#include <queue>

using namespace std;

int main(int argc, char const *argv[]) {
  bool ans=true;
  
  int n;
  cout<<"Enter number of vertices: ";
  cin>>n;
  
  vector<stack<int> > v1(n);
  vector<queue<int> > v2(n);
  
  int temp, nei;
  
  cout<<"for first tree:\n";
  for(int i=0; i<n; i++){
    cout<<"enter number of neighbors of vertex-"<<i+1<<" ";
    cin>>temp;
    cout<<"enter neighbors of vertex-"<<i+1<<" from left to right\n";
    for(int j=0; j<temp; j++){
      cin>>nei;
      (v1[i]).push(nei);
    }
  }
  
  cout<<"for second tree:\n";
  for(int i=0; i<n; i++){
    cout<<"enter number of neighbors of vertex-"<<i+1<<" ";
    cin>>temp;
    cout<<"enter neighbors of vertex-"<<i+1<<" from left to right\n";
    for(int j=0; j<temp; j++){
      cin>>nei;
      (v2[i]).push(nei);
    }
  }
  
  for(int i=0; i<n; i++){
    if(v1[i].size()!=v2[i].size()){
      ans=false;
      break;
    }
    for(int j=0; j<v1[i].size(); j++){
      if(v1[i].top()!=v2[i].front()){
        ans=false;
        break;
      }
      v1[i].pop();
      v2[i].pop();
    }
  }
  
  cout<<ans<<endl;
  
  return 0;
}