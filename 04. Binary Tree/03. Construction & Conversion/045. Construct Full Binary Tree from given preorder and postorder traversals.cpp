#include<iostream>
#include<vector>

using namespace std;

struct node{
  int val;
  struct node *lc, *rc;
};

struct node * newNode(int x){
  struct node *temp = new struct node();
  temp->val = x;
  temp->lc = NULL;
  temp->rc = NULL;
  return temp;
}

vector<int> GetVector(vector<int> vec, int l, int r){
  vector<int> v;
  for(int i=l; i<=r; i++)
    v.push_back(vec[i]);
  return v;
}

void ConstructTree(struct node **head, vector<int>pre, vector<int>post, int n){
  *head = newNode(pre[0]);
  if(pre.size()==1)
    return;
  int left = (pre[1]);
  int lInd = find(post.begin(), post.end(), left) - post.begin();
  int noLeft = lInd+1;
  int noRight = n-lInd-2;
  
  vector<int> preL = GetVector(pre, 1, noLeft);
  vector<int> postL = GetVector(post, 0, lInd);
  ConstructTree(&((*head)->lc), preL, postL, noLeft);
  
  vector<int> preR = GetVector(pre, noLeft+1, n-1);
  vector<int> postR = GetVector(post, lInd+1, n-1);
  ConstructTree(&((*head)->rc), preR, postR, noRight);
}

void PrintTree(struct node *head){
  if(head==NULL)
    return;
  PrintTree(head->lc);
  cout<<head->val<<" ";
  PrintTree(head->rc);
}

int main(int argc, char const *argv[]) {
  int n;
  cin>>n;
  
  vector<int> pre(n);
  vector<int> post(n);
  
  for(int i=0; i<n; i++)
    cin>>pre[i];
  for(int i=0; i<n; i++)
    cin>>post[i];
  
  struct node *head = NULL;
  ConstructTree(&head, pre, post, n);
  
  PrintTree(head);
  return 0;
}