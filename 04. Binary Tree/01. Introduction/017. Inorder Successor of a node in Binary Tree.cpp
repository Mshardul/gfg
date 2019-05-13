#include<iostream>

using namespace std;

struct node{
  int val;
  struct node * lc;
  struct node * rc;
  struct node * parent;
};

struct node * newNode(int x){
  struct node * temp = new struct node();
  temp->val = x;
  temp->lc = NULL;
  temp->rc = NULL;
  return temp;
}

void GetInorderSuccessors(struct node * head, struct node * nd){
  int v = nd->val;
  if(nd->rc!=NULL)
    cout<<nd->rc->val;
  else{
    while(nd->parent->rc==nd)
      nd = nd->parent;
    if(nd==nd->parent->lc)
      cout<<"inorder successor of "<<v<<" is "<<nd->parent->val<<endl;
  }
}

void SetParent(struct node *head, struct node *p){
  if(head==NULL)
    return;
  head->parent = p;
  SetParent(head->lc, head);
  SetParent(head->rc, head);
}

int main(int argc, char const *argv[]) {  
  struct node *head = newNode(1);
  head->lc = newNode(2);
  head->rc = newNode(3);
  head->lc->lc = newNode(4);
  head->lc->rc = newNode(5);
  head->lc->rc->rc = newNode(8);
  head->rc->lc = newNode(6);
  head->rc->rc = newNode(7);
  
  SetParent(head, NULL);
  GetInorderSuccessors(head, head->lc->rc->rc);
  
  return 0;
}