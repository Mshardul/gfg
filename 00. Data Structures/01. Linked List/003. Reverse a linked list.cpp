#include<iostream>

using namespace std;

struct node{
  int val;
  struct node *next;
};

struct node * newNode(int x){
  struct node *temp = new struct node();
  temp->val = x;
  temp->next = NULL;
  return temp;
}

void AddNode(struct node **head, int val){
  struct node *temp = newNode(val);
  if(*head==NULL){
    *head = temp;
    return;
  }
  struct node *x = *head;
  while(x->next!=NULL)
    x = x->next;
  x->next = temp;
}

void PrintReverse(struct node *head){
  if(head==NULL)
    return;
  PrintReverse(head->next);
  cout<<head->val<<" ";
}

void Reverse(struct node **head){ //cant think of anything using recursion
  if((*head)->next == NULL)
    return;
  struct node *curr = *head;
  struct node *prev = NULL;
  (*head) = (*head)->next;
  while((*head)!=NULL){
    curr->next = prev;
    prev = curr;
    curr = (*head);
    (*head) = (*head)->next;
  }
  curr->next = prev;
  *head = curr;
}

void Print(struct node *head){
  if(head==NULL)
    return;
  cout<<head->val<<" ";
  Print(head->next);
}
int main(int argc, char const *argv[]) {
  struct node *head = NULL;
  
  int n;
  cin>>n;
  
  int temp;
  for(int i=0; i<n; i++){
    cin>>temp;
    AddNode(&head, temp);
  }
  
  Print(head);
  cout<<endl;
  
  Reverse(&head);
  cout<<endl;
  
  Print(head);
  cout<<endl;
  
  return 0;
}