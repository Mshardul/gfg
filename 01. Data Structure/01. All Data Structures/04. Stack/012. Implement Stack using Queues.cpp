#include<iostream>
using namespace std;

struct node{
  int val;
  struct node *next;
};

struct node * newNode(int x){
  struct node *temp = new struct node();
  temp->val = x;
  temp->next = NULL;
  return temp;
}

struct node * PopFromStack(struct node *front){
  if(front==NULL || front->next==NULL)
    return NULL;
  struct node *curr = front;
  while(curr->next->next!=NULL)
    curr = curr->next;
  curr->next = NULL;
  return front;
}

void TopOfStack(struct node *front){
  cout<<front->val<<endl;
}

struct node * PushInStack(struct node * front, int x){
  if(front==NULL)
    return newNode(x);
  struct node *curr = front;
  while(curr->next!=NULL)
    curr = curr->next;
  curr->next = newNode(x);
  return front;
}

int main(int argc, char const *argv[]) {
  
  return 0;
}