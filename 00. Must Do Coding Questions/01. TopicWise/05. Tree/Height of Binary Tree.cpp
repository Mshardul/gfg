/* Tree node structure  used in the program
struct Node{
  int data;
  Node* left, *right;
}; */

int DFS(deque<Node *> d){
  if(d.empty())
    return 0;
    
  deque<Node *> ret;
  Node *temp;
  while(!d.empty()){
    temp = d.front();
    d.pop_front();
    if(temp->left!=NULL)
      ret.push_back(temp->left);
    if(temp->right!=NULL)
      ret.push_back(temp->right);
  }
  
  return 1+DFS(ret);
}
int height(Node* node){
  deque<Node *> d;
  d.push_back(node);
  
  int ret = DFS(d);
  return ret;
}