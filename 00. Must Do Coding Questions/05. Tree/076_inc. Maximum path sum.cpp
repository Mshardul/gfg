//this code is for path(head->leaf). whereas question asked for (leaf->leaf)

/*Complete the function below
Node is as follows
struct Node{
	int data;
	Node *left, *right;
};
*/

int GetMaxSum(struct Node * root, int sum, int maxSum){
  if(root->left==NULL && root->right==NULL)
    return max(sum+root->data, maxSum);
  int currSum = sum+root->data;
  if(root->left!=NULL && root->right==NULL)
    return max(sum, GetMaxSum(root->left, currSum, maxSum));
  if(root->right!=NULL && root->left==NULL)
    return max(sum, GetMaxSum(root->right, currSum, maxSum));
  if(root->right!=NULL && root->right!=NULL)
    return max(GetMaxSum(root->left, currSum, maxSum), GetMaxSum(root->right, currSum, maxSum));
}

int maxPathSum(struct Node *root)
{
  if(root==NULL)
    return 0;

  return GetMaxSum(root, 0, INT_MIN);
}