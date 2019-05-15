#include<iostream>
#include<vector>

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

struct node * ReverseGroup(struct node *head, int k){
  struct node *prev = NULL;
  struct node *curr = head;
  head = head->next;
  
  if(head==NULL)
    return head;
  
  int ind = 0;
  
  while(curr!=NULL && ind<k){
    curr->next = prev;
    prev = curr;
    curr = head;
    head = head->next;
    ind++;
  }
  if(head->next==NULL && ind<k){
    head->next = curr;
    curr->next = prev;
    return head;
  }
  return prev;
}

void PrintLL(struct node *head){
  while(head!=NULL){
    cout<<head->val<<" ";
    head = head->next;
  }
  cout<<endl;
}

struct node * ReverseLLInGroups(struct node *head, int k){
  vector<struct node *> groups;
  int ind = 0;
  while(head!=NULL){
    if(ind%k==0){
      groups.push_back(head);
    }
    head = head->next;
    ind+=1;
  }
  struct node *ret = NULL;
  struct node *endNode = NULL;
  
  cout<<"head of groups: ";
  for(vector<struct node *>::iterator iter=groups.begin(); iter!=groups.end(); iter++){
    cout<<(*iter)->val<<" ";
    if(ret==NULL){
      ret = ReverseGroup(*iter, k);
      endNode = ret;
    }
    while(endNode->next!=NULL)
      endNode = endNode->next;
    endNode->next = ReverseGroup(*iter, k);
  }
  cout<<endl;
  PrintLL(ret);
  return ret;
}

int main(int argc, char const *argv[]) {
  int n1, n2, temp, k;
  
  cin>>n1;
  cin>>temp;
  struct node *head = newNode(temp);
  for(int i=1; i<n1; i++){
    cin>>temp;
    AddNode(head, temp);
  }
  
  cin>>k;
  PrintLL(head);
  
  head = ReverseLLInGroups(head, k);

  PrintLL(head);
  
  return 0;
}