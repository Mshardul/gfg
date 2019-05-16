#include<iostream>

using namespace std;

struct node{
  int val;
  struct node *prev, *next;
}

struct node *newNode(int x){
  struct node *temp = new struct node();
  temp->val = x;
  temp->prev = temp;
  temp->next = temp;
  return temp;
}

struct node * TreeToCDLL(struct node *head){
  if(head==NULL)
    return NULL;
  struct node *temp = new struct node();
  struct node *left = TreeToCDLL(head->lc);
  struct node *right = TreeToCDLL(head->rc);
  right->prev->next = left;
  left->prev->next = head;
  head->prev->next = right;
  right->prev = head->prev;
  head->prev = left->prev;
  left->prev = right->prev;
  return left;
}
