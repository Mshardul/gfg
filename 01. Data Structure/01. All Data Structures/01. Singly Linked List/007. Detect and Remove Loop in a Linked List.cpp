#include<iostream>

using namespace std;

struct node{
  int val;
  struct node *next;
}

struct node * newNode(int x){
  struct node *temp = new struct node();
  temp->val = x;
  temp->next = NULL;
  return temp;
}

bool DetectLoop(struct node *head){
  struct node *temp1 = head;
  struct node *temp2 = head;
  while(head1!=NULL || head2->next!=NULL || head3->next!=NULL){
    head1 = head1->next;
    head2 = head2->next->next;
    if(head1==head2)
      return true;
  }
  return false;
}

int GetCycleLen(struct node *head){
  struct node *temp1 = head;
  struct node *temp2 = head;
  while(head1!=NULL || head2->next!=NULL || head3->next!=NULL){
    head1 = head1->next;
    head2 = head2->next->next;
    if(head1==head2)
      break;
  }
  ind ind = 1;
  while(head1!=head2){
    head1 = head1->next;
    head2 = head2->next->next;
    ind++;
  }
  return ind;
}

int RemoveLoop(struct node *head, int n){
  struct node *temp1 = head;
  struct node *temp2 = head;
  for(int i=0; i<n; i++)
    temp2 = temp2->next;
  for(int i=0; i<n; i++){
    temp1 = temp1->next;
    temp2 = temp2->next;
    if(temp1==temp2)
      break;
  }
  while(temp2->next!=temp1)
    temp2 = temp2->next;
  temp2->next = NULL;
}

int main(int argc, char const *argv[]) {
  struct node *head = newNode(1);
  head->next = newNode(2);
  head->next->next = newNode(15); 
  head->next->next->next = newNode(4); 
  head->next->next->next->next = newNode(10); 
  head->next->next->next->next->next = head->next->next;
  
  bool isCycle = DetectLoop(head);
  if(isCycle)
    int n = GetCycleLen(head);
  RemoveLoop(head, n);
  return 0;
}