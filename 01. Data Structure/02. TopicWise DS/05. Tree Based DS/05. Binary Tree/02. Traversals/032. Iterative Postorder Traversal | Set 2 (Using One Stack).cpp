#include<iostream>
#include<stack>

using namespace std;

struct node{
  int val;
  struct node *lc, *rc;
  bool visited;
};

struct node * newNode(int x){
  struct node *temp = new struct node();
  temp->val = x;
  temp->lc = NULL;
  temp->rc = NULL;
  temp->visited = false;
  return temp;
}

void Method1(struct node * head){
  stack<struct node *> st;
  st.push(head);
  head->visited = true;
  
  struct node *left, *right, *temp;
  while(!st.empty()){
    temp = st.top();
    left = temp->lc;
    right = temp->rc;
    if((!left || left->visited==true) && (!right || right->visited==true)){
      cout<<temp->val<<" ";
      st.pop();
      continue;
    }
    if(right!=NULL && right->visited==false){
      st.push(right);
      right->visited = true;
    }
    if(left!=NULL && left->visited==false){
      st.push(left);
      left->visited = true;
    }
  }
  cout<<endl;
}

void Method2(struct node * head){
  stack<struct node *> st;
  st.push(head);
  
  struct node* temp = head;
  while(!st.empty()){
    temp = st.top();
    st.pop();
    if(!st.empty() && temp==st.top()){
      cout<<temp->val<<" ";
      st.pop();
      continue;
    }
    else{
      st.push(temp);
    }
    if(temp->lc==NULL && temp->rc==NULL){
      cout<<temp->val<<" ";
      st.pop();
    }else{
      st.push(temp);
      if(temp->rc!=NULL)
        st.push(temp->rc);
      if(temp->lc!=NULL)
        st.push(temp->lc);
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
  
  Method2(head);
  
  return 0;
}