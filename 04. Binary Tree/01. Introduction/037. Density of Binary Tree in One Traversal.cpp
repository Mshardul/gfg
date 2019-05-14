#include<iostream>
#include<deque>
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

void GetDensity(struct node *head){
  //size = total no of nodes.
  //height = max((no of nodes in the stack/2) + 1)
  stack<struct node *> st;
  st.push(head);
  head->visited = true;
  
  int height = 1, size = 1;
  
  struct node * temp;
  
  while(!st.empty()){
    temp = st.top();
    if(temp->lc && temp->lc->visited==false){
      temp->lc->visited = true;
      st.push(temp->lc);
      size++;
    }else if(temp->rc && temp->rc->visited==false){
      temp->rc->visited = true;
      st.push(temp->rc);
      size++;
    }else{
      st.pop();
    }
    if(st.size()>height)
      height = st.size();
  }
  
  float density = (float)(size)/height;
  cout<<size<<" "<<height<<" "<<density<<endl;
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
  
  GetDensity(head);
  
  return 0;
}