#include <iostream>
#include <stack>
using namespace std;

struct node{
	int val;
	struct node *lc, *rc;
	bool visited;
};

struct node* newNode(int n){
	struct node* temp = new struct node;
	temp->val = n;
	temp->lc = NULL;
	temp->rc = NULL;
	temp->visited = false;
	return temp;
}

void PrintAncestor(struct node* root, int k){
	stack<struct node*> st;
	struct node* temp;
	st.push(root);
	// int x=20;
	while(!st.empty()){
		temp=st.top();
		if(temp->val == k)
			break;
		if((temp->lc != NULL) && (temp->lc->visited == false)){
			cout<<temp->lc->val<<" pushed\n";
			st.push(temp->lc);
		}
		else if((temp->rc != NULL) && (temp->rc->visited == false)){
			cout<<temp->rc->val<<" pushed\n";
			st.push(temp->rc);
		}
		else{
			cout<<temp->val<<" popped\n";
			temp->visited = true;
			st.pop();
		}
	}
	while(!st.empty()){
		cout<<(st.top())->val<<" ";
		st.pop();
	}
	cout<<endl;
}

int main(int argc, char const *argv[])
{
	struct node* root = newNode(1); 
    root->lc = newNode(2); 
    root->rc = newNode(3); 
    root->lc->lc = newNode(4); 
    root->lc->rc = newNode(5); 
    root->rc->lc = newNode(6); 
    root->rc->rc = newNode(7); 
    root->lc->lc->lc = newNode(8); 
    root->lc->rc->rc = newNode(9); 
    root->rc->rc->lc = newNode(10);

    PrintAncestor(root, 5);

	return 0;
}