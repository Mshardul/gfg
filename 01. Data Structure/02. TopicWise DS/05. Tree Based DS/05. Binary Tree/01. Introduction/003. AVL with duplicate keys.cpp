#include <iostream>
using namespace std;

struct node{
  int val;
  struct node *lc, *rc;
};

struct node * newNode(int x){
  struct node * temp = new struct node;
  temp->val = x;
  temp->lc = NULL;
  temp->rc = NULL;
  return temp;
}

void addNode(struct node ** root, int x){
  if(*root==NULL){
    cout<<"added "<<x<<" to root.\n";
    struct node *temp = newNode(x);
    *root = temp;
  }
  else{
    if(((*root)->val)==x)
      cout<<"duplicate detected";
    else if(((*root)->val)>x){
      cout<<"adding "<<x<<" to lc of "<<((*root)->val);
      addNode(&((*root)->lc), x);
    }
    else{
      cout<<"adding "<<x<<" to rc of "<<((*root)->val);
      addNode(&((*root)->rc), x);
    }
    cout<<endl;
  }
}

void Inorder(struct node * root){
  if(root==NULL)
    return;
  Inorder(root->lc);
  cout<<root->val<<" ";
  Inorder(root->rc);
}

int main(int argc, char const *argv[]) {
  int n;
  cin>>n;
  
  int temp;
  
  struct node *root = NULL;
  for(int i=0; i<n; i++){
    cin>>temp;
    addNode(&root, temp);
  }
  
  Inorder(root);
  cout<<endl;
  return 0;
}