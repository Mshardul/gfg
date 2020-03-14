#include <iostream>
using namespace std;

int main(int argc, char const *argv[])
{
	int n;
	cin>>n;
	int a[n];
	
	int top[2]={0, n-1};
	int oper, stack;

	while(1){
		cout<<"1. Push\t2. Pop\t3. Print\t4. Exit\n";
		cin>>oper;

		if(oper==1){
			cout<<"1. Stack1\t2. Stack2\n";
			cin>>stack;
			stack--;

			int ele;
			cout<<"Enter element\n";
			cin>>ele;

			if(top[0]>top[1])
				cout<<"Stack Overflow";
			else
				if(stack==0)
					a[top[0]++]=ele;
				else
					a[top[1]--]=ele;
		}

		else if(oper==2){
			cout<<"1. Stack1\t2. Stack2\n";
			cin>>stack;
			stack--;

			if(stack==0){
				if(top[0]==0)
					cout<<"Stack Underflow";
				else
					cout<<a[--top[0]];
			}
			else{
				if(top[1]==n-1)
					cout<<"Stack Underflow";
				else
					cout<<a[++top[1]];
			}
		}

		else if(oper==3){
			cout<<"Stack1:\n";
			for(int i=0; i<top[0]; i++)
				cout<<a[i]<<" ";
			cout<<endl;

			cout<<"Stack2:\n";
			for(int i=n-1; i>top[1]; i--)
				cout<<a[i]<<" ";
			cout<<endl;
		}

		else
			break;
	}

	return 0;
}