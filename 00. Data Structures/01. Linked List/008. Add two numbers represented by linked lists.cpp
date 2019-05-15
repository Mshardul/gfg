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

struct node * AddCarry(struct node *head, int carry){
  if(head==NULL){
    if(carry==0)
      return NULL;
    return newNode(carry);
  }
  int sum = head->val+carry;
  carry = sum/10;
  sum %= 10;
  struct node *temp = newNode(sum);
  temp->next = AddCarry(head->next, carry);
  return temp;
}

struct node * AddLL(struct node *head1, struct node *head2, int carry){
  if(head1==NULL)
    return AddCarry(head2, carry);
  if(head2==NULL)
    return AddCarry(head1, carry);
    
  int val1 = head1->val;
  int val2 = head2->val;
  
  cout<<val1<<val2<<endl;
  int sum = val1+val2+carry;
  carry = (sum/10);
  sum %= 10;
  
  struct node *head = newNode(sum);
  head->next = AddLL(head1->next, head2->next, carry);
  return head;
}

void Print(struct node *head){
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
  
  struct node* head = AddLL(head1, head2, 0);
  
  Print(head);
  return 0;
}