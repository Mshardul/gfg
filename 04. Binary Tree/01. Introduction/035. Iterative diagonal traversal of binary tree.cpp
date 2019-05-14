#include<iostream>
#include<deque>

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

void DiagonalTraversal(deque<struct node *> *q, deque<struct node *> temp){
  struct node *t;
  while(!temp.empty()){
    int n = temp.size();
    for(int i=0; i<n; i++){
      t = temp.front();
      temp.pop_front();
      if(t->lc!=NULL){
        struct node *x = t->lc;
        while(x!=NULL){
          temp.push_back(x);
          x = x->rc;
        }
      }
    }
    for(deque<struct node *>::iterator iter=temp.begin(); iter!=temp.end(); iter++)
      q->push_back(*iter);
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
  
  deque<struct node*> q;
  struct node * temp = head;
  
  while(temp!=NULL){
    q.push_back(temp);
    temp = temp->rc;
  }
  
  DiagonalTraversal(&q, q);
  
  for(deque<struct node *>::iterator iter = q.begin(); iter!=q.end(); iter++)
    cout<<((*iter)->val)<<" ";
    
  cout<<endl;
  
  return 0;
}