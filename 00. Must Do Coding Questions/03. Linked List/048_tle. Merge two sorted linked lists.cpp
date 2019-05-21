Node* SortedMerge(Node* head1,   Node* head2){
  Node * newHead;
  Node * end;
  
  if((head1->data)>(head2->data)){
    newHead = end = head2;
    head2 = head2->next;
  }else{
    newHead = end = head1;
    head1 = head1->next;
  }
  
  while(head1!=NULL && head2!=NULL){
    if(head1->data>head2->data){
      end->next = newNode(head2->val);
      end = end->next;
      head1 = head1->next;
    }
    else{
      end->next = newNode(head1->val);
      end = end->next;
      head2 = head2->next;
    }
  }
  
  if(head1!=NULL)
    end->next = head1;
  if(head2!=NULL)
    end->next = head2;
  
  return newHead;
}