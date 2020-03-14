#include<iostream>
#include<stack>
#include<string>

using namespace std;

struct node{
  char val;
  struct node * lc;
  struct node * rc;
};

struct node * newNode(char x){
  struct node * temp = new struct node;
  temp->val = x;
  temp->lc = NULL;
  temp->rc = NULL;
  return temp;
}

void Inorder(struct node * head){
  if(head==NULL)
    return;
  Inorder(head->lc);
  cout<<head->val;
  Inorder(head->rc);
}

int main(int argc, char const *argv[]) {
  string s;
  cin>>s;
  
  stack<struct node *> st;
  
  int n = s.length();
  for(int i=0; i<n; i++){
    if(s[i]=='+' || s[i]=='-' || s[i]=='*' || s[i]=='/'){
      struct node * rs = st.top();
      st.pop();
      struct node * ls = st.top();
      st.pop();
      struct node * nd = newNode(s[i]);
      nd->lc = ls;
      nd->rc = rs;
      st.push(nd);
    }
    else{
      struct node * nd = newNode(s[i]);
      st.push(nd);
    }
  }
  
  struct node * head = st.top();
  Inorder(head);

  return 0;
}