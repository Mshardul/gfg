#include<iostream>
using namespace std;

struct Node{
	int data;
	Node *left, *right;
};

/*
int GetMaxSum(struct Node * root, int sum){ //from root to leaf
  if(root==NULL)
    return sum;
  if(root->left==NULL && root->right==NULL)
    return sum+root->data;
  sum += root->data;
  cout<<root->val
  int sumL=INT_MIN, sumR=INT_MIN;
  if(root->left!=NULL)
    sumL = GetMaxSum(root->left, sum);
  if(root->right!=NULL)
    sumR = GetMaxSum(root->right, sum);
  cout<<root->data<<" "<<sumL<<" "<<sumR<<endl;
  return max(sumL, sumR);
}
*/

int GetMaxSum(struct Node * root, int &ans, int curr){ //from leaf to leaf
  if(root==NULL)
    return 0;
  if(root->left==NULL && root->right==NULL)
    return root->data;

  int maxL = GetMaxSum(root->left, ans, curr);
  int maxR = GetMaxSum(root->right, ans, curr);
  int pathSum = maxL + maxR + root->data;
  if(pathSum>ans)
    ans = pathSum;
  return max(maxL, maxR)+root->data;
}

int maxPathSum(struct Node *root)
{
  if(root==NULL)
    return 0
  int sum = 0;
  GetMaxSum(root, sum, 0);
  return sum;
}

Node* newNode(int x){
  Node *temp = new Node();
  temp->data = x;
  temp->left = NULL;
  temp->right = NULL;
  return temp;
}

int main(int argc, char const *argv[]) {
  Node *head = newNode(0);                        //0
  head->left = newNode(1);                        //1
  head->right = newNode(2);                       //2
  head->left->left = newNode(3);                  //4
  head->left->right = newNode(4);                 //5
  head->right->left = newNode(5);                 //7
  head->right->right = newNode(6);                //8
  head->left->left->left = newNode(7);            //11
  head->left->left->right = newNode(8);           //12
  head->left->right->left = newNode(9);           //14
  head->left->right->right = newNode(10);         //15
  head->right->left->left = newNode(11);          //18
  head->right->left->right = newNode(12);         //19
  head->right->right->left = newNode(13);         //21
  head->right->right->right = newNode(14);        //22
  head->left->left->left->left = newNode(15);     //26
  head->left->left->left->right = newNode(16);    //27
  head->left->left->right->left = newNode(17);    //29
  head->left->left->right->right = newNode(18);   //30
  head->left->right->left->left = newNode(19);    //33
  head->left->right->left->right = newNode(20);   //34
  head->left->right->right->left = newNode(21);   //36
  head->left->right->right->right = newNode(22);  //37
  head->right->left->left->left = newNode(23);    //41
  head->right->left->left->right = newNode(24);   //42
  head->right->left->right->left = newNode(25);   //44
  head->right->left->right->right = newNode(26);  //45
  head->right->right->left->left = newNode(27);   //48
  head->right->right->left->right = newNode(28);  //49
  head->right->right->right->left = newNode(29);  //51
  head->right->right->right->right = newNode(30); //52
  
  cout<<maxPathSum(head)<<endl;
  return 0;
}