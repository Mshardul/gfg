/* A binary tree node has data, pointer to left child, and a pointer to right child  
struct Node{
  int data;
  Node* left;
  Node* right;
}; */

void GetLevel(deque<Node *> q, int order){
  if(q.empty())
    return; 
  deque<Node *> res;
  while(!q.empty()){
    Node *temp = q.back();
    cout<<temp->data<<" ";
    q.pop_back();
    if(!order){
      if(temp->right!=NULL)
        res.push_back(temp->right);
      if(temp->left!=NULL)
        res.push_back(temp->left);
    }else{
      if(temp->left!=NULL)
        res.push_back(temp->left);
      if(temp->right!=NULL)
        res.push_back(temp->right);
    }
  }
  GetLevel(res, ~order);
}
void printSpiral(Node *root){
  deque<Node *> q;
  q.push_back(root);
  GetLevel(q, 0);
}