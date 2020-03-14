void pairWiseSwap(struct node *head){
  if(head==NULL || head->next==NULL)
    return;
  head->next = head->next->next;
  head->next->next = head;
  pairWiseSwap(head->next->next);
}