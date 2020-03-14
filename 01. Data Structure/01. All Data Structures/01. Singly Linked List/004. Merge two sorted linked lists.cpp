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

struct node * Merge(struct node *head1, struct node *head2){
  struct node *head = NULL;
  if(head1->val > head2->val){
    head = newNode(head2->val);
    head2 = head2->next;
  }
  else{
    head = newNode(head1->val);
    head1 = head1->next;
  }
  
  struct node *temp = head;
  
  while (head1!=NULL && head2!=NULL) {
    if(head1->val > head2->val){
      AddNode(temp, head2->val);
      head2 = head2->next;
    }else{
      AddNode(temp, head1->val);
      head1 = head1->next;
    }
  }
  
  while(head1!=NULL){
    AddNode(temp, head1->val);
    head1 = head1->next;
  }
  while(head2!=NULL){
    AddNode(temp, head2->val);
    head2 = head2->next;
  }
  
  return head;
}

struct node * MergeRecursive(struct node *head1, struct node *head2){
  if(head1==NULL)
    return head2;
  if(head2==NULL)
    return head1;
  struct node *ret = NULL;
  if(head1->val > head2->val){
    ret = head2;
    ret->next = MergeRecursive(head1, head2->next);
  }else{
    ret = head1;
    ret->next = MergeRecursive(head1->next, head2);
  }
  return ret;
}

void PrintLL(struct node *head){
  while(head!=NULL){
    cout<<head->val<<" ";
    head = head->next;
  }
  cout<<endl;
}

int main(int argc, char const *argv[]) {
  int n1, n2, temp;
  
  cin>>n1;
  cin>>temp;
  struct node *head1 = newNode(temp);
  for(int i=1; i<n1; i++){
    cin>>temp;
    AddNode(head1, temp);
  }
  
  cin>>n2;
  cin>>temp;
  struct node *head2 = newNode(temp);
  for(int i=1; i<n2; i++){
    cin>>temp;
    AddNode(head2, temp);
  }
  
  struct node *head = MergeRecursive(head1, head2);

  PrintLL(head);
  
  return 0;
}