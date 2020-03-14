#include <iostream>
using namespace std;

struct node{
	int data;
	int minTillNow;
	struct node* prev;
	struct node* next;
};

int main(int argc, char const *argv[])
{
	struct node* head=NULL;
	int minEle, ele, ch;

	do{
		cout<<"1.insert\t2.GetLast\t3.RemLast\t4.GetMin:\t";
		cin>>ch;

		if(ch==1){
			cin>>ele;

			struct node* temp=new struct node;
			temp->data=ele;
			temp->next=NULL;
			temp->prev=NULL;
			
			if(head==NULL){
				minEle=ele;
				temp->minTillNow=minEle;
				head=temp;
			}
			else{
				minEle=min(minEle, ele);
				temp->minTillNow=minEle;
				head->next=temp;
				temp->prev=head;
				head=head->next;
			}
		}
		else if(ch==2){
			cout<<"Last element: "<<head->data<<endl;
		}
		else if(ch==3){
			if(head==NULL)
				cout<<"Stack is empty";
			else{
				head=head->prev;
				if(head!=NULL)
					head->next=NULL;
			}
		}
		else if(ch==4){
			cout<<"min element: "<<head->minTillNow<<endl;
		}
	}while(1);

	return 0;
}