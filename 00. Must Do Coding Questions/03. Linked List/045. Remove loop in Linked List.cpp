#include<iostream>

using namespace std;

void removeTheLoop(Node *head){
  struct node * slowPtr = head;
  struct node * fastPtr = head;
  
  bool loop = false;
  while(fastPtr!=NULL && fastPtr->next!=NULL){
    fastPtr = fastPtr->next->next;
    slowPtr = slowPtr->next;
    if(fastPtr==slowPtr){
      loop = true;
      break;
    }
  }
  
  if(!loop)
    return;
  
  fastPtr = head;
  while(fastPtr->next!=slowPtr->next){
    fastPtr = fastPtr->next;
    slowPtr = slowPtr->next;
  }
  slowPtr->next = NULL;
}