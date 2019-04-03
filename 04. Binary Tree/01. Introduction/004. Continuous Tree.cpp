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

int CheckContTree(struct node * root){
  // cout<<"checking for "<<root->val<<endl;
  if(root==NULL)
    return 1;
  int ldiff, rdiff;
  if(root->lc!=NULL){
    ldiff = ((root->val) - (root->lc->val));
    if(ldiff==1 || ldiff==-1){
      ldiff = CheckContTree(root->lc);
      if(ldiff!=1)
        return ldiff;
    }
    else{
      cout<<"conflict between "<<root->val<<" and "<<root->lc->val<<endl;
      return 0;
    }
  }
  if(root->rc!=NULL){
    rdiff = ((root->val) - (root->rc->val));
    if(rdiff==1 || rdiff==-1){
      rdiff = CheckContTree(root->rc);
      if(rdiff!=1)
        return rdiff;
    }
    else{
      cout<<"conflict between "<<root->val<<" and "<<root->rc->val<<endl;
      return 0;
    }
  }
  // cout<<"it is a continuous tree\n";
  return 1;
}

int main(int argc, char const *argv[]) {
  struct node *root = newNode(1);
  root->lc = newNode(2);
  root->rc = newNode(2);
  root->lc->lc = newNode(1);
  root->lc->rc = newNode(3);
  root->rc->lc = newNode(1);
  root->rc->rc = newNode(3);
  
  int x = CheckContTree(root);
  if(x==1)
    cout<<"it is a coutinuous tree\n";
  
  return 0;
}