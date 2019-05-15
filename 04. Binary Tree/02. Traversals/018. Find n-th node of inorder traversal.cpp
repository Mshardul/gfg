#include<iostream>
#include<deque>

using namespace std;

struct node{
  int val;
  struct node * lc;
  struct node * rc;
  int left, right;
};

struct node * newNode(int x){
  struct node * temp = new struct node();
  temp->val = x;
  temp->lc = NULL;
  temp->rc = NULL;
  temp->left = -1;
  temp->right = -1;
  return temp;
}

//method1: was thinking of getting number of left and right children. but something went wrong
void CountChildren(struct node * head){
  if(head==NULL)
    return;
  
  int lNode = 0;
  int rNode = 0;
  
  if(head->lc!=NULL){
    CountChildren(head->lc);
    lNode += head->lc->left + head->lc->right + 1;
  }
  if(head->rc!=NULL){
    CountChildren(head->rc);
    rNode += head->rc->left + head->rc->right + 1;
  }
  
  head->left = lNode;
  head->right = rNode;
  
  cout<<head->val<<" - "<<head->left<<", "<<head->right<<endl;
}

//copied
//method2: static variable that keeps count of the inorder index of the node.
void GetNode(struct node * head, int n){
  static int ind=0;
  if(head==NULL)
    return;
  if(ind<=n){
    GetNode(head->lc, n);
    ind++;
    if(n==ind){
      cout<<head->val<<endl;
      return;
    }
    GetNode(head->rc, n);
  }
}

int main(int argc, char const *argv[]) {
  struct node *head = newNode(1);
  head->lc = newNode(2);
  head->rc = newNode(3);
  head->lc->lc = newNode(4);
  head->lc->rc = newNode(5);
  head->lc->rc->rc = newNode(8);
  head->rc->lc = newNode(6);
  head->rc->rc = newNode(7);
  
  // CountChildren(head);
  
  int index;
  cin>>index;
  
  GetNode(head, index);
  
  return 0;
}