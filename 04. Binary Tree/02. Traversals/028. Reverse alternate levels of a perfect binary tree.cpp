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

void PrintOrder(deque<struct node *> q){
  struct node *temp;
  int n = q.size();
  for(int i=0; i<n; i++){
    temp = q.front();
    cout<<temp->val<<" ";
    q.pop_front();
    if(temp->lc!=NULL)
      q.push_back(temp->lc);
    if(temp->rc!=NULL)
      q.push_back(temp->rc);
  }
  if(!q.empty())
    PrintOrder(q);
}

void RevLevel(struct node * head, deque<struct node *> temp){
  static int level = 0;
  cout<<level<<": ";
  int n = temp.size();
  deque<struct node *> dq;
  if(temp[0]->lc!=NULL){
    for(int i=0; i<n; i++){
      dq.push_back(temp[i]->lc);
      dq.push_back(temp[i]->rc);
    }
    if(level%2==1){
      for(int i=0; i<n; i++){
        temp[i]->lc = dq.back();
        dq.pop_back();
        temp[i]->rc = dq.back();
        dq.pop_back();
      }
    }
    deque<struct node *> x;
    x.push_back(head);
    PrintOrder(x);
    cout<<endl;
    level++;
    if(!dq.empty())
      RevLevel(head, dq);
  }
  else
    return;
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
  q.push_back(head);
  PrintOrder(q);
  cout<<endl;
  
  deque<struct node *> temp;
  if(head->lc!=NULL){
    int t = head->lc->val;
    head->lc->val = head->rc->val;
    head->rc->val = t;
    temp.push_back(head->lc);
    temp.push_back(head->rc);
  }
  
  RevLevel(head, temp);
  
  // q.push_back(head);
  PrintOrder(q);
  cout<<endl;
  
  return 0;
}