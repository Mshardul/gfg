#include<iostream>
#include<stack>
#include<vector>
using namespace std;

// assuming tree to be a full tree

struct node{
  int value;
  struct node *lc, *rc;
};

struct node * CreateNode(int val){
  struct node * temp = new struct node();
  temp->value = val;
  temp->lc = NULL;
  temp->rc = NULL;
  return temp;
}

void CreateTree(vector<int> vec, struct node ** head, int ind, int n){
  int l = 2*ind+1;
  int r = 2*ind+2;
  
  if(l<n){
    (*head)->lc = CreateNode(vec[l]);
    CreateTree(vec, &((*head)->lc), l, n);
  }
  if(r<n){
    (*head)->rc = CreateNode(vec[r]);
    CreateTree(vec, &((*head)->rc), r, n);
  }
  
}

void Prefix(struct node * head){
  if(head==NULL)
    return;
  cout<<head->value<<" ";
  DFS(head->lc);
  DFS(head->rc);
}
int main(int argc, char const *argv[]) {
  int n;
  cin>>n;
  
  vector<int> vec(n);
  for(int i=0; i<n; i++){
    cin>>vec[i];
  }
  
  struct node * head = CreateNode(vec[0]);
  CreateTree(vec, &head, 0, n);
  
  cout<<"output: \n";
  Prefix(head);
  
  return 0;
}