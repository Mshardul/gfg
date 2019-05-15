#include<iostream>
#include<stack>

using namespace std;

struct node{
  char val;
  struct node *lc, *rc;
};

struct node * newNode(char x){
  struct node *temp = new struct node();
  temp->val = x;
  temp->lc = NULL;
  temp->rc = NULL;
  return temp;
}

void ConstructTree(struct node **head, string in, string pre){
  if(in=="")
    return;
  int n = in.length()-1;
  struct node *tempHead = newNode(pre[0]);
  int ind = in.find(pre[0]);
  *head = tempHead;
  if(ind>0)
    ConstructTree((&(*head)->lc), in.substr(0, ind), pre.substr(1, ind+1));
  if(ind<n)
    ConstructTree((&(*head)->rc), in.substr(ind+1, n), pre.substr(ind+1, n));
}

void PrintTree(struct node *head){
  if(head==NULL)
    return;
  if(head->lc!=NULL)
    PrintTree(head->lc);
  cout<<head->val;
  if(head->rc!=NULL)
    PrintTree(head->rc);
}

int main(int argc, char const *argv[]) {
  string in, pre;
  cin>>in;
  cin>>pre;
  
  struct node *head = NULL;
  ConstructTree(&head, in, pre);
  
  PrintTree(head);
  
  return 0;
}