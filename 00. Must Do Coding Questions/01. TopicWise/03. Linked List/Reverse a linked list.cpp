#include<iostream>

using namespace std;

struct node {
  int val;
  struct node *next;
};

struct node * newNode(int x){
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

void Print(struct node *revHead){
  while(revHead!=NULL){
    cout<<revHead->val<<" ";
    revHead = revHead->next;
  }
  cout<<endl;
}

struct node * Reverse(struct node *head){
  struct node *prev = NULL;
  struct node *curr = head;
  struct node *next = head->next;
  while(next!=NULL){
    curr->next = prev;
    prev = curr;
    curr = next;
    next = next->next;
  }
  curr->next = prev;
  return curr;
}

int main(int argc, char const *argv[]) {
  int t;
  cin>>t;
  while(t-->0){
    int n, temp;
    cin>>n;
    
    cin>>temp;
    struct node *head = newNode(temp);
    for(int i=1; i<n; i++){
      cin>>temp;
      AddNode(head, temp);
    }
    
    struct node *revHead = Reverse(head);
    Print(revHead);
  }
  return 0;
}