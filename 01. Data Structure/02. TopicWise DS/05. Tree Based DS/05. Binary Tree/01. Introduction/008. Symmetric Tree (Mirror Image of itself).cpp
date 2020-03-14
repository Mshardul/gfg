#include<iostream>

using namespace std;

struct node{
  int val;
  struct node * lc;
  struct node * rc;
};

struct node * newNode(int x){
  struct node * temp = new struct node;
  temp->val = x;
  temp->lc = NULL;
  temp->rc = NULL;
  return temp;
}

int CheckSymmetry(struct node * head1, struct node * head2){
  if(head1==NULL&&head2==NULL)
    return 1;
  if((head1==NULL&&head2!= NULL)||(head1!=NULL&&head2==NULL)||(head1->val!=head2->val))
    return 0;
  if(head1->val==head2->val){
    int x = CheckSymmetry(head1->lc, head2->rc);
    if(x==0)
      return 0;
    return CheckSymmetry(head1->rc, head2->lc);
  }
}

int main(int argc, char const *argv[]) {
  struct node * head = newNode(1);
  head->lc = newNode(2);
  head->rc = newNode(2);
  head->lc->lc = newNode(3);
  head->lc->rc = newNode(4);
  head->rc->lc = newNode(4);
  head->rc->rc = newNode(3);
  
  int x = CheckSymmetry(head->lc, head->rc);
  if(x==1)
    cout<<"the tree is symmetric";
  else
    cout<<"the tree is not symmetric";
  cout<<endl;
  
  return 0;
}