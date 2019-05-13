#include<iostream>
#include<deque>
#include<iterator>

using namespace std;

struct node{
  int val;
  struct node *lc;
  struct node *rc;
  struct node *next;
};

struct node * newNode(int x){
  struct node *temp = new struct node();
  temp->val = x;
  temp->lc = NULL;
  temp->rc = NULL;
  temp->next = NULL;
  return temp;
}

//method1: T(n): O(n);
void GetInorderSuccessors(struct node * head, deque <struct node * > * successor){
  if(head==NULL)
    return;
  GetInorderSuccessors(head->lc, successor);
  successor->push_back(head);
  GetInorderSuccessors(head->rc, successor);
}

void SetInorderSuccessors(struct node * head, deque<struct node * > * successor){
  if(head==NULL)
    return;
  SetInorderSuccessors(head->lc, successor);
  head->next = successor->front();
  successor->pop_front();
  SetInorderSuccessors(head->rc, successor);
}

void Inorder(struct node *head){
  while(head->lc!=NULL)
    head = head->lc;
  while(head->next!=NULL){
    cout<<head->val<<" "<<head->next->val<<endl;
    head = head->next;
  }
}

void MakeThreaded(struct node *head) {
  deque<struct node *>successor;
  GetInorderSuccessors(head, &successor);
  
  successor.pop_front();
  successor.push_back(NULL);
  
  SetInorderSuccessors(head, &successor);
  
  Inorder(head);
}

//method2: copied
void populateNext(node* p)
{
    static node *next = NULL;
    if (p)
    {
        populateNext(p->rc);
        p->next = next;
        next = p;
        populateNext(p->lc);
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
  
  int method=1;
  
  if(method==1)
    MakeThreaded(head);
  else{
    populateNext(head);
    Inorder(head);
  }
  
  return 0;
}