/* struct Node{
  int data;
  Node *left,  *right;
  Node *nextRight;  // This has garbage value in input trees
}; */
// Should set the nextRight for all nodes

void connectRight(deque<Node *> level){
  if(level.empty())
    return;
    
  deque<Node *> ret;
  Node * first = level.front();
  level.pop_front();
  
  while(!level.empty()){
    if(first->left!=NULL)
      ret.push_back(first->left);
    if(first->right!=NULL)
      ret.push_back(first->right);
    first->nextRight = level.front();
    level.pop_front();
    first = first->nextRight;
  }
  first->nextRight = NULL;
  if(first->left!=NULL)
      ret.push_back(first->left);
  if(first->right!=NULL)
      ret.push_back(first->right);
  connectRight(ret);
}

void connect(Node *p)
{
  deque<Node *> level;
  level.push_back(p);
  connectRight(level);
}
