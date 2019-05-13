#include <iostream>
#include <stack>

using namespace std;

struct node{
  int val;
  struct node * lc;
  struct node * rc;
  bool visited;
};

struct node * newNode(int x){
  struct node * temp = new struct node;
  temp->val = x;
  temp->lc = NULL;
  temp->rc = NULL;
  temp->visited = false;
  return temp;
}

void Inorder(struct node * head){
  struct node * temp;
  stack<struct node *> st;
  if(head==NULL)
    return;
  st.push(head);
  while(!st.empty()){
    temp = st.top();
    st.pop();
    if(temp->visited==true)
      cout<<temp->val<<" ";
    else{
      if(temp->rc!=NULL)
        st.push(temp->rc);
      temp->visited=true;
      st.push(temp);
      if(temp->lc!=NULL)
        st.push(temp->lc);
    }
  }
}

int main(int argc, char const *argv[]) {
  struct node * head = newNode(1);
  head->lc = newNode(2);
  head->rc = newNode(3);
  head->lc->lc = newNode(4);
  head->lc->rc = newNode(5);
  head->rc->lc = newNode(6);
  
  Inorder(head);
  cout<<endl;
  
  return 0;
}