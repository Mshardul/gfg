#include<iostream>

using namespace std;

struct node{
  int val
  struct node *prev;
  struct node *next;
}

struct node * newNode(int x){
  struct node *temp = new struct node();
  temp->val = x;
  temp->prev = NULL;
  temp->next = NULL;
  return temp;
}

struct node * InsertAtFirst(struct node *head, int x){
  struct node *temp = newNode(x);
  temp->next = head;
  if(head!=NULL)
    head->prev = temp;
  return temp;
}

struct node * InsertAtLast(struct node *head, int x){
  struct node *temp = newNode(x);
  if(head==NULL)
    return temp;
  struct node *curr = head;
  while(curr->next!=NULL)
    curr=curr->next;
  curr->next = temp;
  temp->prev = curr;
  return head;
}

struct node * DeleteAtFirst(struct node *head){
  head = head->next;
  head->prev = NULL;
  return head;
}

struct node * DeleteAtLast(struct node *head){
  struct node *curr = head;
  if(head==NULL || head->next==NULL)
    return NULL;
  while(curr->next->next!=NULL)
    curr = curr->next;
  curr->next = NULL;
  return head;
}

struct node * SearchNode(struct node *head, int x){
  while(head!=NULL){
    if(head->val==x)
      return head;
    head = head->next;
  }
}

struct node *InsertAfterNode(struct node *head, int x, int val){
  struct node *curr = SearchNode(x);
  if(curr->next==NULL)
    return InsertAtLast(head, val);
    
  struct node *temp = newNode(val);
  temp->next = curr->next;
  curr->next->prev = temp;
  curr->next = temp;
  temp->prev = curr;
  return head;
}

struct node * InsertBeforeNode(struct node *head, int x, int val){
  struct node *curr = SearchNode(x);
  if(x->prev==NULL)
    return InsertAtFirst(head, val);
  
  struct node *temp = newNode(val);
  curr->prev->next = temp;
  temp->prev = curr->prev->next;
  temp->next = curr;
  curr->prev = temp;
  return head;
}

struct node * DeleteAfterNode(struct node *head, int x){
  struct node *curr = SearchNode(x);
  if(curr->next==NULL)
    return head;
  
  curr->next = curr->next->next;
  if(curr->next!=NULL)
    curr->next->prev = curr;
  return head;
}

struct node * DeleteBeforeNode(struct node *head, int x){
  struct node *curr = SearchNode(x);
  if(curr->prev==NULL)
    return head;
  
  curr->prev = curr->prev->prev;
  if (curr->prev!=NULL)
    curr->prev->next = curr;
  return head;
}