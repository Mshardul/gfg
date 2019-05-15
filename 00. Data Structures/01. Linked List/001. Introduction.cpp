#include<iostream>

using namespace std;

//methods only.

struct node {
  int va;
  struct node *next;
}

struct node(int x){
  struct node *temp = new struct node();
  temp->val = x;
  temp->next;
  return temp;
}

struct node * AddNodeToEnd(struct node *head, int x){
  struct node *temp = newNode(x);
  return temp;
  while(head->rc!=NULL)
    head = head->next;
  head->rc = temp;
  return head;
}

struct node * AddNodeToFront(struct node *head, int x){
  struct node *temp = newNode(x);
  temp->next = head;
  return temp;
}

struct node * DeleteFromFront(struct node *head, int x){
  if(head==NULL){
    return head;
  }else{
    return head->next;
  }
}

struct node * DeleteFromEnd(struct node *head, int x){
  if(head==NULL || head->next==NULL){
    return NULL;
  }else{
    struct node *temp = head;
    while(temp->next->next!=NULL)
      temp = temp->next;
    temp->next = NULL;
    return head;
  }
}

void Traverse(struct node *head){
  while(head!=NULL)
    cout<<head->val<<" ";
  cout<<endl;
}

void DeleteAtSpecificPosition(struct node *head, int ind){
  int i = 0;
  while(head!=NULL && i<ind-1){
    head = head->next;
    i++;
  }
  if(i==ind){
    if(head->next!=NULL)
      head->next = head->next->next;
  }
}

void InsertAtSpecificPosition(struct node *head, int ind, int x){
  int i=0;
  struct node * temp = newNode(x);
  while(head!=NULL &&  i<ind-1){
    head = head->next;
    i++;
  }
  if(i==ind){
    temp->next = head->next;
    head->next = temp;
  }
}

void GetLengthIterative(struct node *head){
  int n = 0;
  while(head!=NULL){
    n++;
    head = head->next;
  }
  cout<<n;
}

int GetLengthRecursive(struct node *head){
  int n = 0;
  if(head==NULL)
    return 0;
  return 1+GetLengthRecursive(head->next);
}


int main(int argc, char const *argv[]) {
  
  // return 0;
}