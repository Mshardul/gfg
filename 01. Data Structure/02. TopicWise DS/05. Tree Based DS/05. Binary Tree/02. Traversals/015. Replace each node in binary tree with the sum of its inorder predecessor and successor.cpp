#include<iostream>
#include<vector>
#include<deque>
#include<iterator>

using namespace std;

//first get the inorder sequence in a vector; then, get the sum sequence in a deque; then overwrite nodes in inorder sequence with values in deque
struct node{
  int val;
  struct node *lc;
  struct node *rc;
};

struct node * newNode(int x){
  struct node *temp = new struct node();
  temp->val = x;
  temp->lc = NULL;
  temp->rc = NULL;
  return temp;
}

void PreorderTraversal(struct node *head){
  if(head==NULL)
    return;
  cout<<head->val<<" ";
  PreorderTraversal(head->lc);
  PreorderTraversal(head->rc);
}

void GetInorderSeq(struct node *head, vector<int>*in){
  if(head==NULL)
    return;
  GetInorderSeq(head->lc, in);
  (*in).push_back(head->val);
  GetInorderSeq(head->rc, in);
}

void ReplaceInorderSeq(struct node *head, deque<int> *vec){
  if(head==NULL)
    return;
  ReplaceInorderSeq(head->lc, vec);
  head->val = (*vec).front();
  (*vec).pop_front();
  ReplaceInorderSeq(head->rc, vec);
}

void Replacement(struct node *head){
  vector<int> in;
  
  in.push_back(0);
  GetInorderSeq(head, &in);
  in.push_back(0);
  
  for(vector<int>::iterator iter = in.begin(); iter<in.end(); iter++)
    cout<<*iter<<" ";
  cout<<endl;
  
  deque<int> inSum;
  for(int i=1; i<in.size()-1; i++)
    inSum.push_back(in[i-1] + in[i+1]);
    
  for(deque<int>::iterator iter = inSum.begin(); iter<inSum.end(); iter++)
    cout<<*iter<<" ";
  cout<<endl;
  
  ReplaceInorderSeq(head, &inSum);
}

int main(int argc, char const *argv[]) {
  struct node *head = newNode(1);
  head->lc = newNode(2);
  head->rc = newNode(3);
  head->lc->lc = newNode(4);
  head->lc->rc = newNode(5);
  head->rc->lc = newNode(6); 
  head->rc->rc = newNode(7); 
  
  PreorderTraversal(head);
  cout<<"----"<<endl;
  
  Replacement(head);
  cout<<"++++"<<endl;
  
  PreorderTraversal(head);
  cout<<"===="<<endl;
  
  return 0;
}