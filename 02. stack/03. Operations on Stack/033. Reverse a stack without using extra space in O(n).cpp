#include <iostream>
using namespace std;

//for linear time and constant space, we can use linked list.
//T(n): O(n); S(n): O(1);
struct node{
	int n;
	struct node *next;
};

void Display(struct node* head){
	struct node* temp=head;
	while(temp!=NULL){
		cout<<temp->n<<" ";
		temp=temp->next;
	}
	cout<<endl;
	free(temp);
}

struct node* Push(struct node* head, int x){
	struct node *temp = new struct node;
	temp->n=x;
	temp->next=NULL;
	if(head!=NULL)
		temp->next=head;
	head=temp;
	return head;
}

struct node* Pop(struct node* head, int x){
	if(head==NULL){
		cout<<"Stack Empty";
		return NULL;
	}
	struct node* temp = head;
	head=head->next;
	delete(temp); //free(temp), in case of malloc;
	return head;
}

struct node* Reverse(struct node* head){
	if(head==NULL || head->next==NULL)
		return head;
	struct node* curr_node = head;
	struct node* prev_node = head;
	struct node* next_node = head->next;
	prev_node->next=NULL;
	while(next_node!=NULL){
		prev_node=curr_node;
		curr_node=next_node;
		next_node=next_node->next;
		curr_node->next=prev_node;
	}
	head=curr_node;
	return head;
}



int main(int argc, char const *argv[])
{
	int n, temp;
	cin>>n;

	struct node* head=NULL;
	for(int i=0; i<n; i++){
		cin>>temp;
		head=Push(head, temp);
	}

	Display(head);

	head=Reverse(head);
	Display(head);
	return 0;
}