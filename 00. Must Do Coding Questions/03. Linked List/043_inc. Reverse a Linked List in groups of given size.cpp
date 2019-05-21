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

struct node * Reverse (struct node *head, int k){
  
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
    
    struct node * revHead = Reverse (head, k);
    
    Print(revHead);
  }
  return 0;
}