void sortList(Node *head){
  int no0=0, no1=0, no2=0;
  
  struct node *curr = head;
  while(curr!=NULL){
    if(head->data==0)
      no0++;
    else if(head->data==1)
      no1++;
    else
      no2++;
  }
  
  curr = head;
  for(int i=0; i<no0; i++){
    curr->data = 0;
    curr = curr->next;
  }
  for(int i=0; i<no1; i++){
    curr->data = 1;
    curr = curr->next;
  }
  for(int i=0; i<no2; i++){
    curr->data = 2;
    curr = curr->next;
  }
}