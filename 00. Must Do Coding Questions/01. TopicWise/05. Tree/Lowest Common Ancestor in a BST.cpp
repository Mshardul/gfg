#include<iostream>
#include<vector>

using namespace std;

struct Node {
  int data;
  Node * right, * left;
};

/*
//look for something
Node* LCA(Node *root, int n1, int n2){
  if(root==NULL || ((root->data)==n1) || ((root->data)==n2) || (((root->data)>n1) && ((root->data)<n2)))
    return root;
  if(((root->data)<n1) && ((root->data)<n2))
    return LCA(root->left, n1, n2);
  if(((root->data)>n1) && ((root->data)>n2))
    return LCA(root->right, n1, n2);
}
*/

void Print(vector<Node*> vec){
  for(vector<Node*>::iterator iter=vec.begin(); iter!=vec.end(); iter++)
    cout<<(*iter)->data<<" ";
  cout<<endl;
}

vector<Node*> GetVector(Node *head, int val, vector<Node*> temp){
  if(head==NULL)
    return vector<Node*>();
  if(head->data==val){
    temp.push_back(head);
    return temp;
  }
  temp.push_back(head);
  vector<Node*> vecL = GetVector(head->left, val, temp);
  if(vecL.empty())
    return GetVector(head->right, val, temp);
  return vecL;
}

Node* LCA(Node *root, int n1, int n2){ //works for any tree
  vector<Node*> vec1 = GetVector(root, n1, vector<Node*>());
  Print(vec1);
  vector<Node*> vec2 = GetVector(root, n2, vector<Node*>());
  Print(vec2);
  
  Node* ans = root;
  int n = min(vec1.size(), vec2.size());
  for(int i=0; i<n; i++){
    if(vec1[i]!=vec2[i])
      break;
    ans = vec1[i];
  }
  return ans;
}

Node* LCA(Node *root, int n1, int n2){ //for BST only
  if((root==NULL) || (root->data<=n1 && root->data>=n2)||(root->data<=n2 && root->data>=n1))
    return root;
  if(root->data<n1 && root->data<n2)
    return LCA(root->right, n1, n2);
  else if(root->data>n1 && root->data>n2)
    return LCA(root->left, n1, n2);
}

Node* newNode(int x){
  Node *temp = new Node();
  temp->data = x;
  temp->left = NULL;
  temp->right = NULL;
  return temp;
}

int main(int argc, char const *argv[]) {
  Node *head = newNode(18);
  head->left = newNode(10);
  head->right = newNode(23);
  head->left->left = newNode(7);
  head->left->right = newNode(8);
  head->right->left = newNode(19);
  head->right->right = newNode(16);
  cout<<(LCA(head, 7, 10))->data<<endl;
  
  return 0;
}