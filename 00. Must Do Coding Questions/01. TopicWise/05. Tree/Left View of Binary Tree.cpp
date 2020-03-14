/* A binary tree node
struct Node{
  int data;
  Node* left, * right;
}; */

void BFS(deque<Node *> currLevel){
  
  if(currLevel.empty())
    return;
  Node *temp = currLevel.front();
  currLevel.pop_front();
  cout<<temp->data<<" ";
  
  deque<Node *> nextLevel;
  if(temp->left!=NULL)
    nextLevel.push_back(temp->left);
  if(temp->right!=NULL)
    nextLevel.push_back(temp->right);
    
  while(!currLevel.empty()){
    temp = currLevel.front();
    currLevel.pop_front();
    if(temp->left!=NULL)
      nextLevel.push_back(temp->left);
    if(temp->right!=NULL)
      nextLevel.push_back(temp->right);
  }
  
  BFS(nextLevel);
}

void leftView(Node *root)
{
  deque<Node *> d;
  d.push_back(root);
  BFS(d);
}