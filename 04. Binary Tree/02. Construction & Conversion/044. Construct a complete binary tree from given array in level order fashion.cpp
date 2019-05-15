#include<iostream>
#include<vector> //using vector instead of linked list - will function similar, except random access
#include<stack>

using namespace std;

struct node{
  int val;
  struct node *lc, *rc;
};

struct node * newNode(int x){
  struct node *temp = new struct node();
  temp->val = x;
  temp->lc = NULL;
  temp->rc = NULL;
  return temp;
}

void ConstructCBTree(struct node **head, vector<int> vec, int ind, int n){
  if(ind>=n)
    return;
  *head = newNode(vec[ind]);
  ConstructCBTree(&((*head)->lc), vec, 2*ind+1, n);
  ConstructCBTree(&((*head)->rc), vec, 2*ind+2, n);
}

void PrintTree(struct node *head){
  if(head==NULL)
    return;
  PrintTree(head->lc);
  cout<<head->val<<" ";
  PrintTree(head->rc);
}

int main(int argc, char const *argv[]) {
  int n;
  cin>>n;
  
  int temp;
  
  vector<int> vec(n);
  for(int i=0; i<n; i++)
    cin>>vec[i];
  
  struct node *head = NULL;
  ConstructCBTree(&head, vec, 0, n);
  
  cout<<"Inorder sequence:\n";
  PrintTree(head);
  cout<<endl;
  
  return 0;
}