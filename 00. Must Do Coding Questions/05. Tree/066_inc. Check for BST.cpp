/* A binary tree node has data, pointer to left child and a pointer to right child  
struct Node {
  int data;
  Node* left, * right;
}; */
bool checkBST(Node *root, node *l, node *r){
  if((l!=NULL && ((l->data)>(root->data))) || (r!=NULL && ((r->data)<(root->data))))
    return false;
  return (checkBST(root->left, l, root) && checkBST(root->right, root, r));
}
bool isBST(Node* root) {
  if(root==NULL || (root->left==NULL && root->right==NULL))
    return true;
  return checkBST(root, root->left, root->right);
}