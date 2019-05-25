/* A binary tree node structure
struct Node {
  int data;
  Node* left, * right;
}; */

int height(Node *root){
  if(root==NULL)
    return 0;
  if (root->left==NULL && root->right==NULL)
    return 1;
  return (max(height(root->left), height(root->right))+1);
}

bool isBalanced(Node *root){
  if(root==NULL)
    return true;
    
  int lHeight = height(root->left);
  int rHeight = height(root->right);
  
  int diffHeight = max(lHeight, rHeight) - min(lHeight, rHeight);
  if(diffHeight>1)
    return false;
  return (isBalanced(root->left) && isBalanced(root->right));
}