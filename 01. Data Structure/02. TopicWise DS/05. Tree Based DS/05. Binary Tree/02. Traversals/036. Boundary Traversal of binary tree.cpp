#include<iostream>
#include<deque>
#include<stack>

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

deque<struct node *> GetLeftNodes(struct node *head){
  deque<struct node *> q;
  while(head->lc!=NULL){
    q.push_back(head);
    head = head->lc;
  }
  return q;
}

deque<struct node *> GetLeafNodes(struct node *head){
  deque<struct node *> q;
  stack<struct node *> st;
  struct node *temp;
  st.push(head);
  while(!st.empty()){
    temp = st.top();
    st.pop();
    if(temp->rc==NULL && temp->lc==NULL)
      q.push_back(temp);
    else{
      if(temp->rc!=NULL)
        st.push(temp->rc);
      if(temp->lc!=NULL)
        st.push(temp->lc);
    }
  }
  return q;
}

deque<struct node *> GetRightNodes(struct node *head){
  deque<struct node *> q;
  while(head->rc!=NULL){
    head = head->rc;
    q.push_back(head);
  }
  return q;
}
void BoundaryTraversal(deque<struct node *> *q, struct node *head){
  deque<struct node *> left = GetLeftNodes(head);
  for(deque<struct node *>::iterator iter = left.begin(); iter!=left.end(); iter++)
    q->push_back(*iter);
    
  deque<struct node *> leaf = GetLeafNodes(head);
  if(q->back()==leaf.front())
    leaf.pop_front();
  for(deque<struct node *>::iterator iter=leaf.begin(); iter!=leaf.end(); iter++)
    q->push_back(*iter);
    
  deque<struct node *> right = GetRightNodes(head);
  if(q->back()==right.back())
    right.pop_back();
  for(deque<struct node *>::reverse_iterator iter=right.rbegin(); iter!=right.rend(); iter++)
    q->push_back(*iter);
  
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
  
  deque<struct node*> q;
  struct node * temp = head;
  
  BoundaryTraversal(&q, head);
  
  for(deque<struct node *>::iterator iter = q.begin(); iter!=q.end(); iter++)
    cout<<((*iter)->val)<<" ";
    
  cout<<endl;
  
  return 0;
}