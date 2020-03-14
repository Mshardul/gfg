/* A binary tree node has data, pointer to left child and a pointer to right child  
struct Node{
  int data;
  Node* left;
  Node* right;
}; */

int countLeaves(Node* root){
  int leaves = 0;
  if(root==NULL)
    return 0;
  if(root->left==NULL & root->right==NULL)
    return 1;
  if(root->left!=NULL)
    leaves += countLeaves(root->left);
  if(root->right!=NULL)
    leaves += countLeaves(root->right);
  return leaves;
}