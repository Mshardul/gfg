#include<iostream>
#include<stack>

using namespace std;

int n; //no of elements in the stack;

struct node{
  int val;
  struct node *prev, *next;
};

struct node * newNode(int x){
  struct node *temp = new struct node();
  temp->val = x;
  temp->prev = NULL;
  temp->next = NULL;
  return temp;
}

void Push(struct node *front, struct node *back, struct node *mid, int x){
  struct node *temp = newNode(x);
  if(front==NULL){
    front = temp;
    back = temp;
    mid = temp;
    n=1;
    return;
  }
  back->next = temp;
  temp->prev = back;
  n++;
  if(n%2==1)
    mid = mid->next;
}

void Pop(struct node *front, struct node *back, struct node *mid){
  if(front==NULL)
    return;
  else if(front==back){
    front = NULL;
    back = NULL;
    mid = NULL;
    n=0;
  }else{
    back = back->prev;
    back->next = NULL;
    n--;
    if(n%2==0)
      mid = mid->prev;
  }
}

void FindMid(struct node *front, struct node *back, struct node *mid){
  if(mid==NULL)
    return;
  cout<<mid->val;
}

void PopMid(struct node *front, struct node *back, struct node *mid){
  if(mid==NULL)
    return;
  if(front==back){
    front = NULL;
    back = NULL;
    mid = NULL;
    n=0;
  }else{
    mid->prev->next = mid->next;
    mid->next->prev = mid->prev;
    n--;
    if(n%2==0)
      mid = mid->prev;
  }
}

int main(int argc, char const *argv[]) {
  
  return 0;
}