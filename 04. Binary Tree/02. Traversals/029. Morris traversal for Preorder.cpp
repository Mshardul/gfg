#include<iostream>
using namespace std;

struct node{
  int val;
  struct node *lc, *rc;
}

struct node * newNode(int x){
  struct node * temp = new stuct node();
  temp->val = x;
  temp->lc = NULL;
  temp->rc = NULL;
  return temp;
}
 //copied
void MorrisPreorder(struct node * head){
  if(head==NULL)
    return;
  if(head->lc==NULL){ //no left child, go to right after printing current(preorder)
    cout<<head->val<<" ";
    head = head->rc;
  }else{
    struct node * pre = head->lc;
    while(pre->rc && pre->rc!=root) //get inorder predecessor, which does not point to current;
      pre = pre->rc;
    if(pre->rc == root){ //inorder predecessor already points to current node => set it back to null, go to right child;
      pre->rc = NULL;
      head = head->rc;
    }else{ //inorder predecessor has no child => print, and make current node its right child => go to left subtree;
      cout<<head->data<<" ";
      pre->rc = root;
      root = root->lc;
    }
  }
}

int main(int argc, char const *argv[]) {
  struct node *head = newNode(1); 

  head->lc = newNode(2); 
  head->rc = newNode(3); 

  head->lc->lc  = newNode(4); 
  head->lc->rc = newNode(5); 
  head->rc->lc  = newNode(6); 
  head->rc->rc = newNode(7); 

  head->lc->lc->lc  = newNode(8); 
  head->lc->lc->rc  = newNode(9); 
  head->lc->rc->lc  = newNode(10); 
  head->lc->rc->rc  = newNode(11); 
  head->rc->lc->lc  = newNode(12); 
  head->rc->lc->rc  = newNode(13); 
  head->rc->rc->lc  = newNode(14); 
  head->rc->rc->rc  = newNode(15); 

  head->lc->lc->lc->lc  = newNode(16); 
  head->lc->lc->lc->rc  = newNode(17); 
  head->lc->lc->rc->lc  = newNode(18); 
  head->lc->lc->rc->rc  = newNode(19); 
  head->lc->rc->lc->lc  = newNode(20); 
  head->lc->rc->lc->rc  = newNode(21); 
  head->lc->rc->rc->lc  = newNode(22); 
  head->lc->rc->rc->rc  = newNode(23); 
  head->rc->lc->lc->lc  = newNode(24); 
  head->rc->lc->lc->rc  = newNode(25); 
  head->rc->lc->rc->lc  = newNode(26); 
  head->rc->lc->rc->rc  = newNode(27); 
  head->rc->rc->lc->lc  = newNode(28); 
  head->rc->rc->lc->rc  = newNode(29); 
  head->rc->rc->rc->lc  = newNode(30); 
  head->rc->rc->rc->rc  = newNode(31);
  
  MorrisPreorder(head);
  return 0;
}