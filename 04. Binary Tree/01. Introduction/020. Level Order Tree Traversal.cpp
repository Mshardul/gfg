#include<iostream>
#include<deque>

using namespace std;

struct node{
  int val;
  struct node *lc, *rc;
};

struct node* newNode(int x){
  struct node * temp = new struct node();
  temp->val = x;
  temp->lc = NULL;
  temp->rc = NULL;
  return temp;
}

void BFSRecurssion(deque<struct node * > *q){
  deque<struct node * > temp;
  struct node * tempNode;
  while(1){
    while(!q->empty()){
      tempNode = q->front();
      q->pop_front();
      cout<<tempNode->val<<" ";
      if(tempNode->lc!=NULL)
        temp.push_back(tempNode->lc);
      if(tempNode->rc!=NULL)
        temp.push_back(tempNode->rc);
    }
    if(temp.empty())
      break;
    while(!temp.empty()){
      q->push_back(temp.front());
      temp.pop_front();
    }
  }
  cout<<endl;
}

void BFSIteration(deque<struct node * > *q){
  struct node * temp;
  while(!q->empty()){
    temp = q->front();
    q->pop_front();
    cout<<temp->val<<" ";
    if(temp->lc!=NULL)
      q->push_back(temp->lc);
    if(temp->rc!=NULL)
      q->push_back(temp->rc);
  }
  cout<<endl;
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
  
  deque<struct node* > q;
  
  q.push_back(head);
  BFSRecurssion(&q);
  
  // q.push_back(head);
  // BFSIteration(&q); //can be done with "head" only
  
  return 0;
}