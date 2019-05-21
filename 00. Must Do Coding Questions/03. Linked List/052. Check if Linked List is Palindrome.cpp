// cant use stack

bool isPalindrome(Node *head){
  int a[25];
  
  Node *slowPtr = head;
  Node *fastPtr = head;
  
  int ind = -1;
  while(fastPtr!=NULL && fastPtr->next!=NULL){
    a[++ind] = slowPtr->data;
    fastPtr = fastPtr->next->next;
    slowPtr = slowPtr->next;
  }
  
  if(fastPtr!=NULL)
    slowPtr = slowPtr->next;
  
  while(slowPtr!=NULL){
    if(slowPtr->data==a[ind]){
      ind--;
      slowPtr = slowPtr->next;
    }
    else{
      return false;
    }
  }
  return true;
}