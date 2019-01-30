#include <iostream>
#include <stack>
using namespace std;

void display(stack<int> s){
	while(!(s.empty())){
		cout<<s.top()<<" ";
		s.pop();
	}
	cout<<endl;
}
int main(int argc, char const *argv[])
{
	int n;
	cin>>n;

	stack<int> stack_orig;
	stack<int> stack_temp;

	int ele, item;

	int oper;
	while(1){
		cout<<"1.Enqueue\t2.Dequeue\t3.Print\t4.Exit\n";
		cin>>oper;
		if(oper==1){
			if(stack_orig.size()==n)
				cout<<"Stack Overflow";
			else{
				cin>>ele;
				stack_orig.push(ele);
			}
		}
		else if(oper==2){
			if(stack_orig.empty())
				cout<<"Stack Overflow";
			else{
				while(stack_orig.size()>1){
					item=stack_orig.top();
					stack_orig.pop();
					stack_temp.push(item);
				}
				cout<<"element popped: "<<stack_orig.top()<<endl;
				stack_orig.pop();
				while(!(stack_temp.empty())){
					item=stack_temp.top();
					stack_temp.pop();
					stack_orig.push(item);
				}
			}
		}
		else if(oper==3)
			display(stack_orig);
		else
			break;
	}
	return 0;
}