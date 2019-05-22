//not taking last inorder node, for some reason

/* Structure for tree and linked list
struct Node{
  int data;
  // left is used as previous and right is used as next in DLL
  Node *left, *right;
}; */

Node * GetInorder(Node * root){
  if(root==NULL || (root->left==NULL && root->right==NULL))
    return root;
    
  Node *l = GetInorder(root->left);
  Node *curr = l;
  while(curr->right!=NULL)
    curr = curr->right;
  
  curr->right = root;
  root->left = curr;
    
  Node *r = GetInorder(root->right);
  root->right = r;
  r->left = curr;
  
  return l;
}
void BToDLL(Node *root, Node **head_ref){  
  head_ref = &(GetInorder(root));
}