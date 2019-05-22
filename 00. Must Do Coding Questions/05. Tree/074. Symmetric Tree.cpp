/*
Structure of the node of the tree is as
struct Node{
	int key;
	struct Node* left, *right;
};
*/

bool CheckSymmetry(Node *l, Node *r){
  if(l==NULL && r==NULL)
    return true;
  if((l==NULL && r!=NULL) || (l!=NULL && r==NULL))
    return false;
  if(l->key != r->key)
    return false;
  return (CheckSymmetry(l->left, r->right) && CheckSymmetry(l->right, r->left));
}

bool isSymmetric(struct Node* root){
  if(root==NULL)
    return true;
  return CheckSymmetry(root->left, root->right);
}