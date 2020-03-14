#include<iostream>
#include<vector>

using namespace std;

struct node{
	int val;
	int count;
	int index;
	struct node *lc;
	struct node *rc;
};

struct node * newNode(int x, int ind){
	struct node *temp = new struct node();
	temp->val = x;
	temp->count = 1;
	temp->index = ind;
	temp->lc = NULL;
	temp->rc = NULL;
	return temp;
}

void Print(vector<struct node*> vec){
	vector<struct node *>::iterator iter = vec.begin();
	while(iter!=vec.end()){
		int n = (*iter)->count;
		for(int i=0; i<n; i++)
			cout<<(*iter)->val<<" ";
		iter++;
	}
	cout<<endl;
}

struct node* BSTEle(vector<int> vec){
	struct node* head = newNode(vec[0], 0);
	int n = vec.size();
	for(int i=1; i<n; i++){
		struct node* temp = head;
		while(temp!=NULL){
			if((temp->val)<(vec[i])){
				if(temp->rc!=NULL){
					temp = temp->rc;
				}else{
					temp->rc = newNode(vec[i], i);
					break;
				}
			}else if((temp->val)>(vec[i])){
				if(temp->lc!=NULL){
					temp = temp->lc;
				}else{
					temp->lc = newNode(vec[i], i);
					break;
				}
			}else{
				temp->count++;
				break;
			}
		}
	}
	return head;
}

struct node* BSTCount(vector<struct node *> vec){
	struct node *head = vec[0];
	int n = vec.size();
	for(int i=1; i<n; i++){
		struct node *temp = head;
		// cout<<vec[i]->val<<" ";
		vec[i]->lc = NULL;
		vec[i]->rc = NULL;
		while(temp!=NULL){
			if((temp->count)>(vec[i]->count)){
				if(temp->rc!=NULL){
					temp = temp->rc;
				}else{
					temp->rc = vec[i];
					break;
				}
			}else if((temp->count)<(vec[i]->count)){
				if(temp->lc!=NULL){
					temp = temp->lc;
				}else{
					temp->lc = vec[i];
					break;
				}
			}else{
				/*
				//smaller index first
				if((temp->index)>(vec[i]->index)){
					if(temp->lc!=NULL){
						temp = temp->lc;
					}else{
						temp->lc = vec[i];
						break;
					}
				}else{
					if(temp->rc!=NULL){
						temp = temp->rc;
					}else{
						temp->rc = vec[i];
						break;
					}
				}
				*/
				if((temp->val)<(vec[i]->val)){
					if(temp->rc!=NULL){
						temp = temp->rc;
					}else{
						temp->rc = vec[i];
						break;
					}
				}else{
					if(temp->lc!=NULL){
						temp = temp->lc;
					}else{
						temp->lc = vec[i];
						break;
					}
				}
			}
		}
	}
	return head;
}

void Inorder(struct node *head, vector<struct node *> &vec){
	if(head==NULL)
		return;
	Inorder(head->lc, vec);
	head->lc = NULL;
	vec.push_back(head);
	Inorder(head->rc, vec);
	head->rc = NULL;
}

int main(int argc, char const *argv[]) {
	int t;
	cin>>t;
	while(t-->0){
		int n;
		cin>>n;
		
		vector<int> vec(n);
		for(int i=0; i<n; i++)
			cin>>vec[i];
			
		struct node* head = BSTEle(vec);
		vector<struct node *> sortedVec;
		Inorder(head, sortedVec);
		// Print(sortedVec);
		
		head = BSTCount(sortedVec);
		vector<struct node *> ans;
		Inorder(head, ans);
		Print(ans);
	}
	return 0;
}