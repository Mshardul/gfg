#include<iostream>

using namespace std;

//copied: T(n): O(n); S(n): O(n);
struct node{
  int val;
  struct node* lc;
  struct node* rc;
};

struct node* newNode(int x){
  struct node* temp = new struct node();
  temp->val = x;
  temp->lc = NULL;
  temp->rc = NULL;
  return temp;
}

void MakeThreaded(struct node * head){
  struct node * pre = new struct node();
  while(head!=NULL){
    if(head->lc==NULL){ //no lc; print it; and go to rc
      cout<<head->val<<" ";
      head = head->rc;
    } else{ //if lc; go to lc
      pre = head->lc;
      while(pre->rc!=NULL && pre->rc!=head) //go to rightmost child of left subtree
        pre = pre->rc;
      if(pre->rc==NULL){ //set rc of rightmost child of left subtree to head; and move to left subtree now
        pre->rc = head;
        head = head->lc;
      }else{ //if rc of rightmost child is not null => it should be pointing to head (ie leftsubtree is done), then print head, release rc of this node and 
        pre->rc = NULL;
        cout<<head->val<<" ";
        head = head->rc;
      }
    }
  }
}
int main(int argc, char const *argv[]) {
  struct node * head = newNode(1);
  head->lc = newNode(2);
  head->rc = newNode(3);
  head->lc->lc = newNode(4);
  head->lc->rc = newNode(5);
  
  MakeThreaded(head);
  return 0;
}