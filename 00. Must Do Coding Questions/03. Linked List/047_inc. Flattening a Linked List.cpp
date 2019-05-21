// should be correct, i think

struct node *flatten(Node *root)
{
  deque<struct node *> temp;
  struct node *curr = root;
  
  int n = 0;
  while(curr!=NULL){
    temp.push_back(curr);
    curr = curr->next;
    n++;
  }
  
  stuct node * newHead = root;
  temp[0] = temp[0]->next;
  
  int min = -1;
  while(1){
    for(int i=1; i<n; i++){
      if(temp[i]!=NULL){
        if((min==-1) || (((temp[min])->val)>((temp[i])->val)))
          min = i;
    }
    if(min==-1)
      break;
    newHead->next = temp[min];
    temp[min] = temp[min]->next;
  }
  
  return newHead;
}