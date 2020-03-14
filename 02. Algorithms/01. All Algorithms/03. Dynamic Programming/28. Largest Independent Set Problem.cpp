#include<iostream>
#include<vector>

using namespace std;

struct node{
	int val;
	struct node *left;
	struct node *right;
};

struct node* newNode(int x){
	struct node *temp = new struct node();
	temp->val = x;
	temp->left = NULL;
	temp->right = NULL;
	return temp;
}

int lis(struct node *root){
	if(root==NULL)
		return 0;
	
	int include = 1;
	int exclude = 0;
	
	exclude = lis(root->left) + lis(root->right);
	
	if(root->left)
		include += lis(root->left->left) + lis(root->left->right);
	if(root->right)
		include += lis(root->right->left) + lis(root->right->right);

	return max(include, exclude);
}

int main(int argc, char const *argv[]) {
	struct node *root = newNode(10);
	root->left = newNode(8);
	root->left->left = newNode(4);
	root->left->right = newNode(12);
	root->left->right->left = newNode(10);
	root->left->right->right = newNode(14);
	root->right = newNode(22);
	root->right->right = newNode(25);
	
	cout<<lis(root)<<endl;
	return 0;
}