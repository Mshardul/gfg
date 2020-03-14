Node*  addTwoLists(Node* first, Node* second){
  int sum = first->data + second->data;
  int carry = sum/10;
  sum %= 10;
  
  Node *head = new Node(sum);
  Node *end = head;
  
  first = first->next;
  second = second->next;
  
  while(first!=NULL && second!=NULL){
    sum = first->data + second->data + carry;
    carry = sum/10;
    sum %= 10;
    
    end->next = new Node(sum);
    end = end->next;
    
    first = first->next;
    second = second->next;
  }
  
  while(first!=NULL){
    sum = first->data + carry;
    carry = sum/10;
    sum %= 10;
    
    end->next = new Node(sum);
    end = end->next;
    
    first = first->next;
  }
  
  while(second!=NULL){
    sum = second->data + carry;
    carry = sum/10;
    sum %= 10;
    
    end->next = new Node(sum);
    end = end->next;
    
    second = second->next;
  }
  
  if(carry!=0)
    end->next = new Node(carry);
  end = end->next;
  
  return head;
}