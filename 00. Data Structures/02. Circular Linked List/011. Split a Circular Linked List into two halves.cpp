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

SplitIntoHalves(struct node *head, int n){
  struct node *head1 = head, *head2 = NULL;
  for(int i=0; i<n/2; i++){
    head = head1->next;
  }
  head2 = head1->next;
  head1->next = head;
  head1 = head2;
  while(head1->next!=NULL)
    head1 = head1->next;
  head1->next = head2;
  
  PrintLL(head1)
  PrintLL(head2);
}

SplitIntoHalves(struct node *head){
  struct node *end1=head, *end2=head;
  
  while(end2->next!=NULL || end2->next->next!=NULL){
    end1 = end1->next;
    end2 = end2->next->next;
  }
  
  if (end2->next->next==NULL) {
    end2 = end2->next;
  }
  
  end2->next = end1->next;
  PrintLL(end1->next); //second half
  end1->next = head;
  PrintLL(head); //first half
}

int main(int argc, char const *argv[]) {
  
  return 0;
}