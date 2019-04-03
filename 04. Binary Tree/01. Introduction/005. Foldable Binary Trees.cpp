#include <iostream>
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

int IsFoldable(struct node * head1, struct node * head2){
  if((head1==NULL && head2!=NULL) || (head1!=NULL && head2==NULL)){
    int ans;
    if(head1!=NULL)
      ans=head1->val;
    else
      ans=head2->val;
    cout<<"conflict with "<<ans<<endl;
    return 0;
  }
  else if(head1==NULL && head2==NULL)
    return 1;
  int ans = IsFoldable(head1->lc, head2->rc);
  if(ans!=0)
    return IsFoldable(head1->rc, head2->lc);
  return 0;
}

int main(int argc, char const *argv[]) {
  struct node * head = newNode(10);
  head->lc = newNode(7);
  head->rc = newNode(15);
  head->lc->lc = newNode(9);
  head->rc->lc = newNode(11);
  
  int x = IsFoldable(head->lc, head->rc);
  
  if(x==1)
    cout<<"the tree is foldable\n";
  
  return 0;
}