#include <iostream>
#include <stack>
using namespace std;

//using dfs

struct node{
	int data;
	struct node *lc, *rc;
	bool visited;
};

struct node* newNode(int x){
	struct node *n = new struct node();
	n->data=x;
	n->lc=NULL;
	n->rc=NULL;
	n->visited=false;
	return n;
}

void DispAncestor(stack<struct node *> st){
	while(!st.empty()){
		cout<<(st.top())->data<<" ";
		st.pop();
	}
	cout<<endl;
}
void GetAncestor(int x, struct node *head){
	// cout<<"GetAncestor";
	stack<struct node *> st;
	st.push(head);
	struct node *temp;
	while(!st.empty()){
		temp=st.top();
		// cout<<temp->data;
		if(temp->data==x){
			DispAncestor(st);
			return;
		}
		else{
			if(temp->lc!=NULL && temp->lc->visited==false){
				st.push(temp->lc);
				temp->lc->visited=true;
			}
			else if(temp->rc!=NULL && temp->rc->visited==false){
				st.push(temp->rc);
				temp->rc->visited=true;
			}
			else{
				st.pop();
			}
		}
	}
}

int main(int argc, char const *argv[])
{
	struct node* root = newNode(1); 
  root->lc = newNode(2); 
  root->rc = newNode(7); 
  root->lc->lc = newNode(3); 
  root->lc->rc = newNode(5); 
  root->rc->lc = newNode(8); 
  root->rc->rc = newNode(9); 
  root->lc->lc->lc = newNode(4); 
  root->lc->rc->rc = newNode(6); 
  root->rc->rc->lc = newNode(10); 
	GetAncestor(10, root);
	return 0;
}