#include<iostream>
#include<stack>
#include<queue>

using namespace std;

int main(int argc, char const *argv[]) {
  int n;
  cin>>n;
  
  int temp;
  queue<int> q;
  for(int i=0; i<n; i++){
    cin>>temp;
    q.push(temp);
  }
  
  queue<int> q2;
  for(int i=0; i<(n/2); i++){
    q2.push(q.front());
    q.pop();
  }
  
  while(!q2.empty()){
    q.push(q2.front());
    q.push(q.front());
    q2.pop();
    q.pop();
  }
  if(n%2==1){
    q.push(q.front());
    q.pop();
  }
  
  while(!q.empty()){
    cout<<q.front()<<" ";
    q.pop();
  }
  cout<<endl;
  
  return 0;
}