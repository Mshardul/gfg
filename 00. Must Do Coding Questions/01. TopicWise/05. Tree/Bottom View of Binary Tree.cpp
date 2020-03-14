struct Node{
  int data; //data of the node
  Node *left, *right; //left and right references
  Node(int key){
    data = key;
    left = right = NULL;
  }
};

void Print(map<int, int> mp){
  map<int, int>::iterator iter = mp.begin();
  while(iter!=mp.end()){
    int x = iter->first;
    int y = iter->second;
    cout<<y<<" ";
    iter++;
  }
}

void recurse(Node* root, int ind, map<int, int> &mp){
  mp[ind] = root->data;
  if(root->left)
    recurse(root->left, ind-1, mp);
  if(root->right)
    recurse(root->right, ind+1, mp);
}

void bottomView(Node *root){
  map<int, int> mp;
  recurse(root, 0, mp);
  Print(mp);
}