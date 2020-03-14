#include <iostream>
using namespace std;

struct node{
	int data;
	struct node* next;
	struct node* prev;
};

int main(int argc, char const *argv[])
{
	int n;
	cin>>n;

	struct node* top[n];
	for(int i=0; i<n; i++)
		top[i]=NULL;

	int ele, ch, st;
	while(1){
		cout<<"1.Push\t2.Pop\t3.Display: ";
		cin>>ch;

		cout<<"Enter stack number: ";
		cin>>st;

		if(ch==1){
			cout<<"Enter element: ";
			cin>>ele;

			struct node* temp = new struct node;
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
			top[st]=top[st]->prev;
			if(top[st]!=NULL)
				top[st]->next=NULL;
		}
		else if(ch==3){
			struct node* temp=top[st];
			while(temp!=NULL){
				cout<<temp->data<<" ";
				temp=temp->prev;
			}
			cout<<endl;
		}
		else
			break;
	}
	return 0;
}