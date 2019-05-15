#include<iostream>

using namespace std;

struct node{
  int va;
  struct node *next;
}

struct node * newNode(int x){
  struct node *temp = new struct node();
  temp->val = x;
  temp->next = temp;
}

void PrintLL(struct node *head){
  while(head!=NULL)
    cout<<head->val<<" ";
  cout<<endl;
}

struct node * InsertSorted(struct node *head, int x){
  struct node *temp = new struct node(x);
  if(head==NULL)
    return temp;
  if(head->val>x)
    InsertAtFirst(head, x);
  else{
    struct node *curr = head;
    while(curr->next!=head){
      if(curr->val<x && curr->next->val>x){
        break;
      curr = curr->next;
      }
    }
    temp->next = curr->next;
    curr->next = temp->next;
  }
}

int main(int argc, char const *argv[]) {
  /* code */
  return 0;
}