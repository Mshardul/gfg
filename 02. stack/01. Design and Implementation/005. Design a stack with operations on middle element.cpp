#include <iostream>
#include <stack>
using namespace std;

//no more upper limit of elements from now on
struct dll
{
	int data;
	struct dll* prev;
	struct dll* next;
};

int main(int argc, char const *argv[])
{
	int ch, ele;

	struct dll* mid=NULL;
	struct dll* top=NULL;

	int oddNodes=0;

	while(1){
		cout<<"1.push\t2.pop\t3.print\t4.displayMid\t5.deleteMid\n";
		cin>>ch;

		if(ch==1){
			cin>>ele;
			struct dll* temp;
			temp->data=ele;
			temp->prev=NULL;
			temp->next=NULL;
			if(top==NULL){
				top=temp;
				mid=temp;
			}
			else{
				top->next=temp;
				temp->prev=top;
				top=temp;
				if(oddNodes==1)
					mid=mid->next;
			}
			oddNodes=~oddNodes;
		}
		else if(ch==2){
			if(top==NULL)
				cout<<"Empty Stack";
			else{
				top=top->prev;
				top->next=NULL;
				if(oddNodes==1)
					mid=mid->prev;
				oddNodes=~oddNodes;
			}
		}
		else if(ch==3){
			struct dll* temp=top;
			while(temp!=NULL){
				cout<<temp->data<<" ";
				temp=temp->prev;
			}
			cout<<endl;
		}
		else if(ch==4)
			cout<<mid->data<<endl;
		else if(ch==5){
			if(mid->prev==NULL){
				if(mid->next==NULL){//only one node in the stack{
					mid=NULL;
					top=NULL;
				}
				else{
					mid=mid->next;
					mid->prev=NULL;
				}
			}
			else{
				mid->next->prev=mid->prev;
				mid=mid->prev;
				mid->next=mid->next->next;
			}
			oddNodes=~oddNodes;
		}
	}

	return 0;
}