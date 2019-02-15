#include <iostream>
#include <stack>
using namespace std;

//T(n): O(n); S(n): O(n)=θ(log n);
struct node{
	int val;
	struct node* left;
	struct node* right;
	bool visited; //so that to know if the node is visited
}node;

void TraverseUsingRecursion(struct node* root){ //using recursion
	if(root->left!=NULL)
		TraverseUsingRecursion(root->left);
	if(root->right!=NULL)
		TraverseUsingRecursion(root->right);
	cout<<root->val<<" ";
}

void TraverseUsingOneStacks(struct node* root){
	stack<struct node* > st;
	struct node* temp;
	root->visited=true;
	st.push(root);
	while(!st.empty()){
		temp=st.top();
		if((temp->left==NULL || temp->left->visited==true) && (temp->right==NULL || temp->right->visited==true)){
			cout<<temp->val<<" ";
			st.pop();
		}
		else{
			if(temp->right!=NULL && temp->right->visited==false){
				temp->right->visited=true;
				st.push(temp->right);
			}
			if(temp->left!=NULL && temp->left->visited==false){
				temp->left->visited=true;
				st.push(temp->left);
			}
		}
	}
}

struct node* newNode(int n){
	struct node* temp = new struct node;
	temp->val = n;
	temp->left = NULL;
	temp->right = NULL;
	temp->visited = false;
	return temp;
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

	TraverseUsingOneStacks(root);
	cout<<endl;

	return 0;
}