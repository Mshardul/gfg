#include<iostream>

using namespace std;

struct node{
  int val;
  struct node * lc;
  struct node * rc;
};

struct node * newNode(int x){
  struct node * temp = new struct node;
  temp->val = x;
  temp->lc = NULL;
  temp->rc = NULL;
  return temp;
}

void Inorder(struct node * head){
  if(head==NULL)
    return;
  Inorder(head->lc);
  cout<<head->val<<" ";
  Inorder(head->rc);
}

void Preorder(struct node * head){
  if(head==NULL)
    return;
  cout<<head->val<<" ";
  Preorder(head->lc);
  Preorder(head->rc);
}

void Postorder(struct node * head){
  if(head==NULL)
    return;
  Postorder(head->lc);
  Postorder(head->rc);
  cout<<head->val<<" ";
}

int main(int argc, char const *argv[]) {
  struct node * head = newNode(1);

  Inorder(head);
  cout<<endl;
  Preorder(head);
  cout<<endl;
  Postorder(head);
  cout<<endl;
  
  return 0;
}