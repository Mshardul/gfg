#include<iostream>
#include<deque>
#include<vector>

using namespace std;

void GetMaxOfSubArrays(vector<int> vec, int n, int k){
  deque<int> q;
  q.push_back(0);
  int i=1;
  while(i<k){
    while(!q.empty() && vec[q.back()]<vec[i]){
      q.pop_back();
    }
    q.push_back(i++);
  }
  cout<<vec[q.front()]<<" ";
  while(i<n){
    while(!q.empty() && vec[q.back()]<vec[i]){
      q.pop_back();
    }
    q.push_back(i++);
    if((i-q.front())>k)
      q.pop_front();
    cout<<vec[q.front()]<<" ";
  }
  cout<<endl;
}

int main(int argc, char const *argv[]) {
  int t;
  cin>>t;
  
  while(t-->0){
    int n, k;
    cin>>n>>k;
    
    vector<int> vec(n);
    for(int i=0; i<n; i++)
      cin>>vec[i];
    
    GetMaxOfSubArrays(vec, n, k);
  }
  return 0;
}