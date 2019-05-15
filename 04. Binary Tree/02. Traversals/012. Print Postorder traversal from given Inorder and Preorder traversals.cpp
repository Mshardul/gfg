#include <iostream>
#include <vector>

using namespace std;
//assuming it to be unique combination

int preInd = 0;
void GetPost(vector<int> pre, vector<int> in, int l, int r){
  if(l>r)
    return;
  int val = pre[preInd++];
  int inInd = find(in.begin()+l, in.begin()+r, val) - in.begin(); //get index where "val" resides in "in"
  GetPost(pre, in, l, inInd-1);
  GetPost(pre, in, inInd+1, r);
  cout<<in[inInd]<<" "; //root printed at end of traversal
}

int main(int argc, char const *argv[]) {
  int n;
  cin>>n;
  
  vector<int> pre(n);
  vector<int> in(n);
  
  for(int i=0; i<n; i++)
    cin>>pre[i];
  for(int i=0; i<n; i++)
    cin>>in[i];
  
  GetPost(pre, in, 0, n-1);
  
  return 0;
}