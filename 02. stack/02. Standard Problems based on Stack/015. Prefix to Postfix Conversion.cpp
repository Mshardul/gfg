//use stack for operands.
//traverse string from r to l
//on getting an operator
	//pop 2 elements x and y from stack
	//push x+y+operator into the stack

#include <iostream>
#include <stack>
#include <string>
using namespace std;

int main(int argc, char const *argv[])
{
	stack<string> s;

	string str, x, y, ch;
	cin>>str;

	int n=str.size();

	for(int i=n-1; i>-1; i--){
		ch=str[i];
		if(ch=="+" || ch=="-" || ch=="*" || ch=="/"){
			x=s.top();
			s.pop();
			y=s.top();
			s.pop();
			s.push(x+y+ch);
		}
		else if(ch==";"){
			break;
		}
		else{
			s.push(ch);
		}
	}
	cout<<s.top()<<endl;
	return 0;
}