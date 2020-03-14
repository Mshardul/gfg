#include <iostream>
using namespace std;

//didnot dry-run
struct node{
	struct node *prev;
	int data;
	struct node *next;
};

class stack{
	struct node *head;
	int n;

public:
	stack(){
		head=NULL;
		n=0;
	}

	int size(){
		return n;
	}

	int isEmpty(){
		if(size()==0)
			return 1;
		return 0;
	}

	void push(int ele){
		n++;
		struct node* temp = new struct node;

		temp->data=ele;
		temp->prev=NULL;
		temp->next=NULL;

		if(isEmpty())
			head=temp;
		else{
			head->next=temp;
			temp->prev=head;
			head->next=head;
		}
	}

	int pop(){
		if(isEmpty())
			return -1;	//stack is empty
		n--;
		int ele=head->data;
		head=head->prev;
		if(head!=NULL)
			head->next=NULL;
		return ele;
	}

	void display(){
		struct node* temp=head;

		while(temp!=NULL){
			cout<<temp->data<<" ";
			temp=temp->prev;
		}
		cout<<endl;
	}

};

class queue
{
	struct node *rear, *front;
	int n;

public:
	queue(){
		rear=NULL;
		front=NULL;
		n=0;
	}

	int size(){
		return n;
	}

	int isEmpty(){
		if(size()==0)
			return 1;
		return 0;
	}

	void enqueue(int ele){
		struct node* temp=new struct node;
		temp->data=ele;
		temp->prev=NULL;
		temp->next=NULL;

		if(isEmpty()){
			rear=temp;
			front=temp;
		}
		else{
			rear->next=temp;
			temp->prev=rear;
			rear=temp;
		}
	}

	int dequeue(){
		if(isEmpty())
			return -1; //queue is empty;
		int ele=front->data;
		front=front->next;
		if(front!=NULL)
			front->prev=NULL;
		return ele;
	}

	void display(){
		struct node* temp=front;
		while(temp!=NULL){
			cout<<temp->data<<" ";
			temp=temp->next;
		}
	}
};

int main(int argc, char const *argv[])
{
	stack *s=new stack();
	queue *q=new queue();

	return 0;
}