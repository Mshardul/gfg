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

		if(ch==1){ //push
			cin>>ele;
			struct dll* temp=new struct dll;
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
				if(oddNodes==0) //even number of elements before inserting new node
					mid=mid->next;
			}
			oddNodes=~oddNodes;
		}
		else if(ch==2){ //pop
			if(top==NULL)
				cout<<"Empty Stack"<<endl;
			else{
				top=top->prev;
				if(top!=NULL)
					top->next=NULL;
				if(oddNodes==1) //odd number of elements before popping top
					mid=mid->prev;
				oddNodes=~oddNodes;
			}
		}
		else if(ch==3){ //print
			struct dll* temp=top;
			if(top==NULL)
				cout<<"Empty Stack";
			else{
				while(temp!=NULL){
					cout<<temp->data<<" ";
					temp=temp->prev;
				}
			}
			cout<<endl;
		}
		else if(ch==4) //display min
			cout<<mid->data<<endl;
		else if(ch==5){ //delete min
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