#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>

using namespace std;

void Print(priority_queue<int, vector<int>, greater<int> > q){
  while(!q.empty()){
    int tp = q.top();
    cout<<tp<<" ";
    q.pop();
  }
  cout<<endl;
}

int minPlatform(vector<int> a, vector<int> d, int n){
  vector<pair<int, int> > vec(n);
  for(int i=0; i<n; i++){
    pair<int, int> p = make_pair(a[i], d[i]);
    vec[i] = p;
  }
  sort(vec.begin(), vec.end());
  priority_queue<int, vector<int>, greater<int> >q;
  for(int i=0; i<n; i++){
    pair<int, int> p = vec[i];
    if(!q.empty() && q.top()<p.first){
      q.pop();
    }
    q.push(p.second);
  }
  return q.size();
}

int main(int argc, char const *argv[]) {
  int t;
  cin>>t;
  
  while(t-->0){
    int n;
    cin>>n;
    
    vector<int> a(n);
    vector<int> d(n);
    
    for(int i=0; i<n; i++)
      cin>>a[i];
      
    for(int i=0; i<n; i++)
      cin>>d[i];
      
    cout<<minPlatform(a, d, n)<<endl;
  }
  return 0;
}

