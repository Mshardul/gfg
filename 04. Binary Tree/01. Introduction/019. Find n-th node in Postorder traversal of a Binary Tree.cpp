#include <iostream>

using namespace std;

struct node{
  int val;
  struct node *lc;
  struct node *rc;
};

struct node * newNode(int x){
  struct node *temp = new struct node();
  temp->val = x;
  temp->lc = NULL;
  temp->rc = NULL;
  return temp;
}

void GetNode(struct node *head, int n){
  static int ind = 0;
  if(head==NULL)
    return;
  if(head){
    GetNode(head->lc, n);
    GetNode(head->rc, n);
    ind++;
    if(ind==n){
      cout<<head->val<<endl;
      return;
    }
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
  
  int n;
  cin>>n;
  
  GetNode(head, n);
  
  return 0;
}