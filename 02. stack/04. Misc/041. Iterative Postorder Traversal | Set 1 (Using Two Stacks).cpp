#include <iostream>
#include <stack>
using namespace std;

struct node{
	int val;
	struct node* left;
	struct node* right;
};

struct node* newNode(int n){
	struct node* temp = new struct node;
	temp->val = n;
	temp->left = NULL;
	temp->right = NULL;
	return temp;
}

void TraverseUsingTwoStacks(struct node* root){
	struct node* temp;
	stack<struct node*> st, st2;
	st.push(root);
	while(!st.empty()){
		temp = st.top();
		st2.push(temp);
		st.pop();
		if(temp->left!=NULL)
			st.push(temp->left);
		if(temp->right!=NULL)
			st.push(temp->right);
	}
	while(!st2.empty()){
		temp=st2.top();
		cout<<temp->val<<" ";
		st2.pop();
	}
}

int main(int argc, char const *argv[])
{
	struct node* root = NULL; 
    root = newNode(1); 
    root->left = newNode(2); 
    root->right = newNode(3); 
    root->left->left = newNode(4); 
    root->left->right = newNode(5); 
    root->right->left = newNode(6); 
    root->right->right = newNode(7); 

	TraverseUsingTwoStacks(root);
	cout<<endl;
	return 0;
}