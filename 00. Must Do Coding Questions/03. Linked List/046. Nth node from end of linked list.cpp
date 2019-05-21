#include<iostream>

using namespace std;

int getNthFromLast(Node *head, int n){
  int ind = 0;
  struct node *fastPtr = head;
  while(fastPtr!=NULL && ind<n){
    fastPtr = fastPtr->next;
    ind++;
  }
  
  if(fastPtr==NULL && ind<n-1)
    return -1;
  while(fastPtr!=NULL){
    fastPtr = fastPtr->next;
    head = head->next;
  }
  return head->val;
}