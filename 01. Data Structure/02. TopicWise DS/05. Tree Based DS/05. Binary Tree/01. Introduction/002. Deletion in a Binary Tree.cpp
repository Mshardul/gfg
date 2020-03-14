#include<iostream>

using namespace std;

struct node{
  int val;
  struct node *lc;
  struct node *rc;
};

struct node * newNode(int x){
  struct node * temp = new struct node;
  temp->val = x;
  temp->lc = NULL;
  temp->rc = NULL;
  return temp;
}

struct node * SearchNode(struct node * root, int x){
  if(root==NULL || root->val==x)
    return root;
  struct node * subtree;
  if(root->lc!=NULL)
    subtree = SearchNode(root->lc, x);
    if(subtree!=NULL)
      return subtree;
  if(root->rc!=NULL)
    subtree = SearchNode(root->lc, x);
    if(subtree!=NULL)
      return subtree;
  return NULL;
}

struct node * GetRightMostNode(struct node * root){
  if(root==NULL || root->rc==NULL)
    return root;
  return GetRightMostNode(root->rc);
}

void DelRightMostNode(struct node ** root, struct node * rmNode){
  if((*root)==NULL)
    return;
  if((*root)==rmNode){
    (*root) = ((*root)->lc);
  }
  else if(((*root)->rc)==rmNode){
    ((*root)->rc)=NULL;
  }
}

void Inorder(struct node * root){
  if(root==NULL)
    return;
  Inorder(root->lc);
  cout<<root->val<<" ";
  Inorder(root->rc);
}

int main(int argc, char const *argv[]) {
  
  struct node *root = newNode(1);
  root->lc = newNode(2);
  root->rc = newNode(3);
  root->lc->lc = newNode(4);
  root->rc->lc = newNode(6);
  root->rc->rc = newNode(7);
  
  cout<<"Printing\n";
  Inorder(root);
  
  int temp;
  cin>>temp;
  
  struct node * toDel = SearchNode(root, temp); //get pointer to the node-to-delete
  struct node * rmNode = GetRightMostNode(root); //set the value of right-most-node as the value of node-to-delete
  toDel->val = rmNode->val;
  DelRightMostNode(&root, rmNode); //delete right-most-node
  Inorder(root);
  return 0;
}