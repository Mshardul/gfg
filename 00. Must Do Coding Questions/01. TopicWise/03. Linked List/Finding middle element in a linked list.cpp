#include<iostream>
using namespace std;

struct node{
  int val;
  struct node * next;
};

struct node *newNode(int x){
  struct node *temp = new struct node();
  temp->val = x;
  temp->next = NULL;
  return temp;
}

void addNode(struct node *head, int x){
  struct node *temp = newNode(x);
  while(head->next!=NULL)
    head = head->next;
  head->next = temp;
}

void FindMid(struct node *head){
  struct node *slowPtr = head;
  struct node *fastPtr = head;
  while(fastPtr!=NULL && fastPtr->next!=NULL){
    slowPtr = slowPtr->next;
    fastPtr = fastPtr->next->next;
  }
  return slowPtr->val;
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
      addNode(head, temp);
    }
  
    cout<<FindMid(head)<<endl;
  }
  return 0;
}