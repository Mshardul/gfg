#include <iostream>
using namespace std;

int main(int argc, char const *argv[])
{
	int n;
	cin>>n;

	int a[n];

	int top1=-1;
	int top2=n;

	int oper, stack, ele;

	while(1){
		cout<<"1.Stack1\t2.Stack2\n"; //default is stack2
		cin>>stack;

		cout<<"1.Push\t2.Pop\t3.Print\t4.Exit\n"; //default is exit
		cin>>oper;

		if(oper==1){
			if(top2-top1<2)
				cout<<"Stack Overflow"<<endl;
			else{
				cin>>ele;
				if(stack==1)
					a[++top1]=ele;
				else
					a[--top2]=ele;
			}
		}
		else if(oper==2){
			if(stack==1){
				if(top1==-1)
					cout<<"Stack empty";
				else
					cout<<"Element popped: "<<a[top1--];
			}
			else{
				if(top2==n)
					cout<<"Stack Empty";
				else
					cout<<"Element popped: "<<a[top2++];
			}
		}
		else if(oper==3){
			cout<<"Stack1: \n";
			for(int i=top1; i>-1; i--)
				cout<<a[i]<<" ";
			cout<<endl;
			cout<<"Stack2: \n";
			for(int i=top2; i<n; i++)
				cout<<a[i]<<" ";
			cout<<endl;
		}
		else
			break;
	}

	return 0;
}