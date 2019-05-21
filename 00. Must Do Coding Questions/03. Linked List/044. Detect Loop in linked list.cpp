#include<iostream>

using namespace std;

struct node{
  int val;
  struct node *next;
};

struct node *newNode(int x){
  struct node *temp = new struct node();
  temp->val = x;
  temp->next = NULL;
  return temp;
}

void AddNode(struct node *head, int x){
  struct node *temp = newNode(x);
  while(head->next!=NULL)
    head = head->next;
  head->next = temp;
}

int detectloop(Node *head){
  struct node *slowPtr = head;
  struct node *fastPtr = head;
  while(fastPtr!=NULL && fastPtr->next!=NULL){
    fastPtr = fastPtr->next->next;
    slowPtr = slowPtr->next;
    if(slowPtr==fastPtr)
      return 1;
  }
  return 0;
}