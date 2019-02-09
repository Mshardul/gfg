#include <iostream>
#include <stack>
using namespace std;

//assuming single digit numbers
//something is wrong here. will check again.
//T(n): O(n); S(n): O(n);
int main(int argc, char const *argv[])
{
	char ch, op;
	stack<char> st_o;
	stack<int> st_v;
	int a, b;
	do{
		cin>>ch;
		cout<<ch;
		if(isdigit(ch)){
			// cout<<"pushing";
			st_v.push(ch-'0');
			// cout<<"pushed";
		}
		else if(ch=='(')
			st_o.push(ch);
		else if(ch=='+' || ch=='-'){
			// cout<<"pushing";
			while(!st_o.empty() || st_o.top()!='('){
				op=st_o.top();
				b=st_v.top();
				st_v.pop();
				a=st_v.top();
				st_v.pop();
				if(op=='+')
					st_v.push(a+b);
				else if(op=='-')
					st_v.push(a-b);
				else if(op=='*')
					st_v.push(a*b);
				else if(op=='/')
					st_v.push(a/b);
			}
			st_o.push(ch);
			// cout<<"pushed";
		}
		else if(ch=='*' || ch=='/'){
			while(!st_o.empty() || st_o.top()!='(' || st_o.top()!='+' || st_o.top()!='-'){
				op=st_o.top();
				b=st_v.top();
				st_v.pop();
				a=st_v.top();
				st_v.pop();
				if(op=='*')
					st_v.push(a*b);
				else if(op=='/')
					st_v.push(a/b);
			}
			st_o.push(ch);
		}
		else if(ch==')'){
			while(!st_o.empty() || st_o.top()!='('){
				op=st_o.top();
				b=st_v.top();
				st_v.pop();
				a=st_v.top();
				st_v.pop();
				if(op=='+')
					st_v.push(a+b);
				else if(op=='-')
					st_v.push(a-b);
				else if(op=='*')
					st_v.push(a*b);
				else if(op=='/')
					st_v.push(a/b);
			}
			if(st_o.top()=='(')
				st_o.pop();
		}
	}while(ch!=';');
	cout<<st_v.top()<<endl;
	return 0;
}