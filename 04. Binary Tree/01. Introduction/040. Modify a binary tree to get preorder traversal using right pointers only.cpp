#include<iostream>

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

void Method(struct node *head){
  struct node *right, *temp;
  while(head!=NULL){
    cout<<head->val<<" ";
    if(head->lc!=NULL){
      right = head->rc;
      head->rc = head->lc;
      head->lc = NULL;
      head = head->rc;
      temp = head;
      while(temp->rc!=NULL)
        temp=temp->rc;
      temp->rc = right;
    }
    else{
      head = head->rc;
    }
  }
  cout<<endl;
}

int main(int argc, char const *argv[]) {
  struct node *head = newNode(10);
  head->lc = newNode(8);
  head->lc->lc = newNode(3);
  head->lc->rc = newNode(5);
  head->rc = newNode(2);
  head->rc->rc = newNode(7);
  
  Method(head);
  
  return 0;
}