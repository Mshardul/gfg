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
  q.push_back(head);
  
  struct node *temp;
  int level = 0;
  while(!q.empty()){
    int nodesInLevel = q.size();
    if(level%4<=1){
      for(int i=0; i<nodesInLevel; i++){
        temp = q.front();
        cout<<temp->val<<" ";
        q.pop_front();
        if(temp->lc!=NULL)
          q.push_back(temp->lc);
        if(temp->rc!=NULL)
          q.push_back(temp->rc);
      }
    }
    else{
      for(int i=0; i<nodesInLevel; i++){
        temp = q.back();
        cout<<temp->val<<" ";
        q.pop_back();
        if(temp->rc!=NULL)
          q.push_front(temp->rc);
        if(temp->lc!=NULL)
          q.push_front(temp->lc);
      }
    }
    cout<<endl;
    level++;
  }
  return 0;
}