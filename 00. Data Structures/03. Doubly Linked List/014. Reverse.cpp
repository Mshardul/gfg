#include<iostream>

using namespace std;

struct node{
  int val;
  struct node *next, *prev;
}

struct node *newNode(struct node *head, int x){
  struct node *temp = new struct node();
  temp->val = x;
  temp->prev = NULL;
  temp->next = NULL;
  return temp;
}

struct node *Reverse(struct node *head){
  if(head==NULL)
    return head;
  
  struct node *curr = head;
  struct node *temp = NULL;
  while(curr!=NULL){
    temp = curr->prev;
    curr->prev = curr->next;
    curr->next = temp;
    curr=curr->prev;
  }
}