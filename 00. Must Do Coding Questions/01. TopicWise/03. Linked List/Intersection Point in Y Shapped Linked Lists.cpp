int intersectPoint(Node* head1, Node* head2){
  int n=0, m=0;
  Node *curr = head1;
  while(curr!=NULL){
    n++;
    curr = curr->next;
  }
  
  curr = head2;
  while(curr!=NULL){
    m++;
    curr = curr->next;
  }
  
  int gt = max(n, m);
  if(gt==n){
    while(n-->m){
      head1 = head1->next;
    }
  }
  else{
    while(m-->n){
      head2 = head2->next;
    }
  }
  while(head1->next!=head2->next){
    head1 = head1->next;
    head2 = head2->next;
  }
  if(head1->next==NULL)
    return -1;
  return head1->next->data;
}