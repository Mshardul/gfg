#include<iostream>
#include<vector>

using namespace std;

//inorder of BST is always sorted;

int preInd = 0;

void GetPost(vector<int> pre, vector<int> in, int l, int r){
  if(l>r)
    return;
  int val = pre[preInd++];
  int inInd = find(in.begin(), in.end(), val) - in.begin();
  GetPost(pre, in, l, inInd-1);
  GetPost(pre, in, inInd+1, r);
  cout<<in[inInd]<<" ";
}

int main(int argc, char const *argv[]) {
  int n, temp;
  cin>>n;
  
  vector<int> pre(n);
  vector<int> in(n);
  
  for(int i=0; i<n; i++){
    cin>>temp;
    pre[i] = temp;
    in[i] = temp;
  }
    
  sort(in.begin(), in.end());
  
  GetPost(pre, in, 0, n-1);
  return 0;
}