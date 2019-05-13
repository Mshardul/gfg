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

void SpiralLOT(struct node *head, deque<struct node *> *q){
  static int forward = 1;
  struct node *temp;
  deque<struct node*> tempQ;
  // cout<<forward<<": ";
  while(!q->empty()){
    temp = q->front();
    cout<<temp->val<<" ";
    q->pop_front();
    if(temp->lc!=NULL)
      tempQ.push_back(temp->lc);
    if(temp->rc!=NULL)
      tempQ.push_back(temp->rc);
  }
  // cout<<endl;
  while (!tempQ.empty()){
    if(forward%2==1){
      q->push_back(tempQ.front());
      tempQ.pop_front();
      
    }else{
      q->push_back(tempQ.back());
      tempQ.pop_back();
    }
  }
  forward++;
  if(!q->empty())
    SpiralLOT(head, q);
}
int main(int argc, char const *argv[]) {
  struct node *head = newNode(1);
  head->lc = newNode(2);
  head->rc = newNode(3);
  head->lc->lc = newNode(4);
  head->lc->rc = newNode(5);
  head->lc->rc->rc = newNode(8);
  head->rc->lc = newNode(6);
  head->rc->rc = newNode(7);
  
  deque<struct node *> q;
  q.push_back(head);
  
  SpiralLOT(head, &q);
  return 0;
}