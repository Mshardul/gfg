/* A binary tree node has data, pointer to left child and a pointer to right child  
struct Node {
  int data;
  Node* left, * right;
}; */
/*using extra space*/
void Print(vector<int> vec){
  vector<int>::iterator iter = vec.begin();
  while(iter!=vec.end()){
    cout<<*iter<<" ";
    iter++;
  }
  cout<<endl;
}

bool Inorder(struct Node *root, vector<int> &vec){
  if(root->left!=NULL)
    Inorder(root->left, vec);
  vec.push_back(root->data);
  if(root->right!=NULL)
    Inorder(root->right, vec);
}

bool isBST(struct Node* root) {
  if(root==NULL)
    return true;
  vector<int> vec;
  Inorder(root, vec);
  Print(vec);
  int n = vec.size();
  for(int i=1; i<n; i++){
    if(vec[i]<vec[i-1])
      return false;
  }
  return true;
}

/*without using extra space*/
bool checkBST(struct Node* root, int mn, int mx){
  if(!(root->data>=mn && root->data<=mx))
    return false;
  bool l=true, r=true;
  if(root->left)
    l = checkBST(root->left, mn, min(mx, root->data));
  if(root->right)
    r = checkBST(root->right, max(mn, root->data), mx);
  return l&&r;
}

bool isBST(struct Node* root){
  if(root==NULL)
    return true;
  return checkBST(root, INT_MIN, INT_MAX);
}