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

void AddAtEnd(struct node *head, int x){
  struct node *temp = newNode(x);

  while(head->next!=NULL)
    head = head->next;
  head->next = temp;
}

int GetInd(struct node *head, int val){
  int ind = 0;
  while(head!=NULL){
    ind++;
    head = head->next;
    if(head->val==val)
      return ind;
  }
  return -1;
}

struct node * GetPrev(struct node *head, int ind1){
  int ind=1;
  while(ind<ind1){
    head=head->next;
    ind++;
  }
  return head;
}

void Swap(struct node *head, int ind1, int ind2){
  struct node *node1, *node2;
  
  node1 = GetPrev(head, ind1);
  node2 = GetPrev(head, ind2);
  
  cout<<node1->val<<" "<<node2->val<<endl;
  
  struct node *temp1 = node1->next;
  struct node *temp2 = node2->next;

  node1->next = temp1->next;
  node2->next = temp2->next;
  
  temp1->next = node2->next;
  temp2->next = node1->next;
  
  node1->next = temp2;
  node2->next = temp1;
}

void Print(struct node *head){
  while(head!=NULL){
    cout<<head->val<<" ";
    head = head->next;
  }
  cout<<endl;
}
int main(int argc, char const *argv[]) {
  int n;
  cin>>n;
  
  int temp;
  struct node *head = newNode(-100); //dummy node;
  
  for(int i=0; i<n; i++){
    cin>>temp;
    AddAtEnd(head, temp);
  }
  
  Print(head);
  
  int val1, val2;
  cin>>val1>>val2;
  
  int ind1 = GetInd(head, val1);
  int ind2 = GetInd(head, val2);
  
  cout<<ind1<<" "<<ind2<<endl;
  
  if(ind1==-1 || ind2==-1)
    cout<<"no such number";
  else
    Swap(head, ind1, ind2);
    
  Print(head);
  
  return 0;
}