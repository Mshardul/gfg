#include<iostream>
#include<stack>

using namespace std;

struct node{
  string val;
  struct node * lc;
  struct node * rc;
};

struct node * newNode(string x){
  struct node * temp = new struct node;
  temp->val = x;
  temp->lc = NULL;
  temp->rc = NULL;
  return temp;
}

int getVal(char op, int l, int r){
  if(op=='+')
    return l+r;
  else if(op=='-')
    return l-r;
  else if(op=='*')
    return l*r;
  return l/r;
}

int toInt(string x){
  int num = 0;
  int st = 0;
  if(x[0]=='-')
    st=1;
  int n = x.length();
  for(int i=st; i<n; i++){
    num = num*10 + (x[i]-48);
  }
  if(x[0]=='-')
    num*=-1;
  return num;
}

int eval(struct node * root){
  string x = root->val;
  if(x!="+" && x!="-" && x!="*" && x!="/"){
    return toInt(x);
  }
  else{
    int l = eval(root->lc);
    int r = eval(root->rc);
    int ans = getVal(((root->val)[0]), l, r);
    return ans;
  }
}

int main(){
  struct node *root = newNode("+");
  root->lc = newNode("*");
  root->lc->lc = newNode("5");
  root->lc->rc = newNode("-4");
  root->rc = newNode("-");
  root->rc->lc = newNode("100");
  root->rc->rc = newNode("20");
  cout << eval(root) << endl;
}