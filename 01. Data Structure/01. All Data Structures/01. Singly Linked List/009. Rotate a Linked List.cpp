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

void AddNode(struct node *head, int x){
  struct node *temp = newNode(x);
  while(head->next!=NULL)
    head = head->next;
  head->next = temp;
}

void Rotate(struct node **head, int k){
  struct node *temp = *head;
  for(int i=0; i<k-1; i++)
    (*head) = (*head)->next;
  struct node *end = *head;
  (*head) = (*head)->next;
  end->next = NULL;
  end = *head;
  while(end->next!=NULL)
    end = end->next;
  end->next = temp;
}

void Print(struct node * head){
  while(head!=NULL){
    cout<<head->val<<" ";
    head = head->next;
  }
  cout<<endl;
}

int main(int argc, char const *argv[]) {
  int n, temp, k;
  cin>>n;
  
  cin>>temp;
  struct node * head = newNode(temp);
  for(int i=1; i<n; i++){
    cin>>temp;
    AddNode(head, temp);
  }
  
  Print(head);
  
  cin>>k;
  
  k = k%n;
  Rotate(&head, k);
  
  Print(head);
  return 0;
}