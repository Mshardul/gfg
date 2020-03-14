#include <iostream>
#include <stack>
using namespace std;

int main(int argc, char const *argv[])
{
	stack<int> st;
	char ch;
	int a, b;
	do{
		cin>>ch;
		if(isdigit(ch))
			st.push(ch-'0');
		else{
			b=st.top();
			st.pop();
			if(st.empty())
				break;
			a=st.top();
			st.pop();
			if(ch=='+')
				st.push(a+b);
			else if(ch=='-')
				st.push(a-b);
			else if(ch=='*')
				st.push(a*b);
			else if(ch=='/')
				st.push(a/b);
		}
	}while(ch!=';');
	cout<<b<<endl;
	return 0;
}