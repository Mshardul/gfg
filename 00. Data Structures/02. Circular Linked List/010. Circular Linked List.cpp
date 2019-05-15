#include<iostream>

using namespace std;

struct node{
  int val;
  struct node *next;
}

struct node * newNode(int x){
  struct node *temp = new struct node();
  temp->val = x;
  temp->next = temp;
  return temp;
}

struct node * InsertAtFirst(struct node * head, int x){
  struct node *temp = newNode(x);
  if(head==NULL){
    return temp;
  }
  
  temp->next = head;
  struct node *curr = head;
  while(curr->next!=head)
    curr = curr->next;
  
  curr->next = temp;
  return temp;
}

struct node * InsertAtLast(struct node * head, int x){
  struct node *temp = newNode(x);
  if(head==NULL)
    return temp;
  
  temp->next = head;
  struct node *curr = head;
  while(curr->next!=head)
    curr = curr->next;
  curr->next=temp;
  return head;
}

struct node * InsertAtIndex(struct node *head, int ind, int x){ //inserting at (ind)th index
  if(ind==0 || head==NULL)
    return InsertAtFirst(head, x);
    
  struct node *temp = newNode(x);
    
  struct node *curr = head;
  for(int i=1; i<ind; i++){
    curr = curr->next;
  }
  temp->next = curr->next;
  curr->next = temp;
  return head;
}

struct node * DeleteAtFront(struct node *head){
  if(head==NULL || head->next==NULL)
    return NULL;
  struct node *curr = head;
  while(curr->next!=head)
    curr = curr->next;
  curr->next = head->next;
  return head->next;
}

struct node * DeleteAtLast(struct node *head){
  if(head==NULL || head->next==NULL)
    return NULL;
  struct node *curr = head;
  while(curr->next->next!=head)
    curr = curr->next;
  curr->next = head;
  return head;
}

struct node * DeleteAtIndex(struct node *head, int ind){
  if(ind==0 || head==NULL)
    return DeleteAtFront(head);
  struct node *curr = head;
  for(int i=1; i<ind; i++)
    curr = curr->next;
  curr->next = curr->next->next;
  return head;
}

struct Traverse(struct node *head){
  struct node *curr = head;
  while(curr->next!=head)
    cout<<curr->val<<" ";
  cout<<curr->val<<endl;
}

int main(int argc, char const *argv[]) {
  return 0;
}