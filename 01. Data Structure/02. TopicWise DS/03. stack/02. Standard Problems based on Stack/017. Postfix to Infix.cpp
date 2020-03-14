//use stack for operands.
//traverse string from r to l
//on getting an operator
	//pop 2 elements x and y from stack
	//push y+operator+x into the stack

#include <iostream>
#include <stack>
using namespace std;

int main(int argc, char const *argv[])
{
	stack<string> s;

	string str, x, y, ch;

	cin>>str;
	int n=str.size();

	for(int i=0; i<n; i++){
		ch=str[i];
		if(ch=="+" || ch=="-" || ch=="*" || ch=="/"){
			x=s.top();
			s.pop();
			y=s.top();
			s.pop();
			s.push(y+ch+x);
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