#include<iostream>
#include<deque>
#include<vector>

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

void GetRev(deque<struct node *> *q, deque<struct node *> tempQ){
  static int iter = 0;
  
  if(tempQ.empty())
    return;
    
  deque<struct node *> local;
  struct node *temp;
  int i=0;
  for(deque<struct node *>::iterator iter = tempQ.begin(); iter<tempQ.end(); iter++){
    temp = *iter;
    if(temp->lc!=NULL)
      local.push_back(temp->lc);
    if(temp->rc!=NULL)
      local.push_back(temp->rc);
  }
  
  GetRev(q, local);
    
  while(!tempQ.empty()){
    q->push_back(tempQ.front());
    tempQ.pop_front();
  }
}

int main(int argc, char const *argv[]) {
  struct node *head = newNode(1);
  head->lc = newNode(2); 
  head->rc = newNode(3); 
  head->lc->lc = newNode(4); 
  head->lc->rc = newNode(5); 
  head->rc->lc = newNode(6); 
  head->rc->rc = newNode(7); 
  head->lc->lc->lc = newNode(8); 
  head->lc->lc->rc = newNode(9); 
  head->lc->rc->lc = newNode(3); 
  head->lc->rc->rc = newNode(1); 
  head->rc->lc->lc = newNode(4); 
  head->rc->lc->rc = newNode(2); 
  head->rc->rc->lc = newNode(7); 
  head->rc->rc->rc = newNode(2); 
  head->lc->rc->lc->lc = newNode(16); 
  head->lc->rc->lc->rc = newNode(17); 
  head->rc->lc->rc->lc = newNode(18); 
  head->rc->rc->lc->rc = newNode(19);
  
  deque<struct node *> q;
  deque<struct node *> tempQ;
  
  tempQ.push_back(head);
  
  GetRev(&q, tempQ);
  
  while(!q.empty()){
    cout<<q.front()->val<<" ";
    q.pop_front();
  }
  
  cout<<endl;
  
  return 0;
}