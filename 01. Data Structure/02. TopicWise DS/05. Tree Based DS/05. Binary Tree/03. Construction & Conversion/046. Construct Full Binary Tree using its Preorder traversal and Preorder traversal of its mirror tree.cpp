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

void ConstructTree(struct node **head, vector<int> pre, vector<int> preM, int n){
  *head = newNode(pre[0]);
  if(pre.size()==1)
    return;
  int left = pre[1];
  int ind = find(preM.begin(), preM.end(), left) - preM.begin();
  int noR = ind-1;
  int noL = n-noR-1;
  
  vector<int> preL = GetVector(pre, 1, noL);
  vector<int> preML = GetVector(preM, ind, n-1);
  ConstructTree(&((*head)->lc), preL, preML, noL);
  
  vector<int> preR = GetVector(pre, noL+1, n-1);
  vector<int> preMR = GetVector(preM, 1, noR);
  ConstructTree(&((*head)->rc), preR, preMR, noR);
  
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
  vector<int> preM(n);
  
  for(int i=0; i<n; i++)
    cin>>pre[i];
  for(int i=0; i<n; i++)
    cin>>preM[i];

  struct node *head = NULL;
  
  ConstructTree(&head, pre, preM, n);
  
  PrintTree(head);
  cout<<endl;
  
  return 0;
}