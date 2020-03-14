#include<iostream>
#include<deque>

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

void PrintOrder(deque <struct node *> *q, deque <struct node *> temp){
  struct node *left, *right;
  // deque<struct node *> tempQ;
  int n = temp.size();
  for(int i=0; i<n/2; i++){
    left = temp.front();
    temp.pop_front();
    right = temp.front();
    temp.pop_front();
    cout<<"--> "<<left->val<<" "<<right->val<<endl;
    if(left->lc!=NULL){
      temp.push_back(left->lc);
      temp.push_back(right->rc);
      temp.push_back(left->rc);
      temp.push_back(right->lc);
    }
  }
  // while(!temp.empty()){
  //   q->push_front(temp.back());
  //   temp.pop_back();
  // }
  for(deque<struct node *>::reverse_iterator iter = temp.rbegin(); iter!=temp.rend(); iter++){
    q->push_front(*iter);
  }
    
  if(!temp.empty()){
    cout<<"nothing found\n";
    PrintOrder(q, temp);
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
  
  deque<struct node *> q;
  deque<struct node *> temp;
  
  q.push_back(head);
  
  if(head->lc!=NULL){
    q.push_front(head->rc);
    q.push_front(head->lc);
    temp.push_back(head->lc);
    temp.push_back(head->rc);
    PrintOrder(&q, temp);
  }
  
  
  while(!q.empty()){
    cout<<q.front()->val<<" ";
    q.pop_front();
  }
  
  cout<<endl;
  
  return 0;
}