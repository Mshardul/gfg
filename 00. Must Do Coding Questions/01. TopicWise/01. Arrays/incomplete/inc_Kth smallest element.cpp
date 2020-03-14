//TLE: O(n log n); required: O(n);

#include<iostream>
#include<queue>

using namespace std;

int main(int argc, char const *argv[]) {
  int t;
  cin>>t;
  
  while(t-->0){
    int n, k, temp;
    cin>>n;
    
    priority_queue<int, vector<int>, greater<int> > q;
    for(int i=0; i<n; i++){
      cin>>temp;
      q.push(temp);
    }
    
    cin>>k; //assuming k>=n
    for(int i=1; i<k; i++)
      q.pop();
    int ans = q.top();
    cout<<ans<<endl;
  }
  return 0;
}