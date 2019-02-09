#include <iostream>
using namespace std;

struct node{
	int data;
	struct node* prev;
	struct node* next;
};

int main(int argc, char const *argv[])
{
	struct node* top[2]={NULL, NULL};

	int ele, ch, st;

	while(1){
		cout<<"0.Stack1\t1.Stack2:\t";
		cin>>st;
		if(st!=0)
			st=1;

		cout<<"1.Push\t2.Pop\t3.Print\t4.Merge:\t";
		cin>>ch;

		if(ch==1){
			cout<<"Enter ele:\t";
			cin>>ele;

			struct node* temp=new struct node;
			temp->data=ele;
			temp->prev=NULL;
			temp->next=NULL;

			if(top[st]==NULL)
				top[st]=temp;
			else{
				top[st]->next=temp;
				temp->prev=top[st];
				top[st]=temp;
			}
		}
		else if(ch==2){
			if(top[st]==NULL)
				cout<<"Stack is empty\n";
			else{
				top[st]=top[st]->prev;
				if(top[st]!=NULL)
					top[st]->next=NULL;
			}
		}
		else if(ch==3){
			struct node* temp=top[st];
			if(temp==NULL)
				cout<<"Stack is empty";
			while(temp!=NULL){
				cout<<temp->data<<" ";
				temp=temp->prev;
			}
			cout<<endl;
		}
		else if(ch==4){
			struct node* temp=top[!st];
			if(temp!=NULL){
				while(temp!=NULL){
					top[st]->next=temp;
					temp=temp->prev;
					top[st]->next->prev=top[st];
					top[st]=top[st]->next;
				}
				top[!st]=NULL;
			}
		}
		else
			break;
	}
	return 0;
}