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

struct node * Rotate(struct node *head, int k){
  struct node *curr = head;
  while(--k>0)
    curr = curr->next;
  struct node *newHead = curr->next;
  curr->next = NULL;
  curr = newHead;
  while(curr->next!=NULL)
    curr = curr->next;
  curr->next = head;
  return newHead;
}

void Rotate(struct node **head, int k){
  int n = 0;
  struct node *oldHead = *head;
  while(oldHead!=NULL){
    n++;
    oldHead = oldHead->next;
  }
  k = k%n;
  if(k==0)
    return;
  oldHead = *head;
  struct node *curr = *head;
  while(--k>0)
    curr = curr->next;
  *head = curr->next;
  curr->next = NULL;
  curr = *head;
  while(curr->next!=NULL)
    curr = curr->next;
  curr->next = oldHead;
}

void Print(struct node *head){
  while(head!=NULL){
    cout<<head->val<<" ";
    head = head->next;
  }
  cout<<endl;
}

int main(int argc, char const *argv[]) {
  int t;
  cin>>t;
  while(t-->0){
    int n, temp, k;
    cin>>n;
    
    cin>>temp;
    struct node *head = newNode(temp);
    for(int i=1; i<n; i++){
      cin>>temp;
      AddNode(head, temp);
    }
    
    cin>>k;
    
    Rotate(&head, k%n);
    Print(head);
  }
  return 0;
}