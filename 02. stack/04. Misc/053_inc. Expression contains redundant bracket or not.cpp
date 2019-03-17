#include <iostream>
#include <stack>
using namespace std;

//assuming parenthesis' to be balanced
//at least an operator between ')/(' and '('
//at least an operator between '(' and ')'
//one operator just before '(', except for first one
int main(int argc, char const *argv[])
{
	string s;
	cin>>s;

	int i=1;
	char ch;
	bool oper=false, ans=true;
	stack<char> st;
	st.push(s[0]);
	do{
		if(ch=='('){
			if(st.top()=='+' || st.top()=='-' || st.top()=='*' || st.top()=='/')
				st.push(ch);
			else{
				ans=false;
				break;
			}
		}
		else if(ch==')'){
			if(oper==true){

			}
		}
	}while(s[++i]!='\0');

	if(ans)
		cout<<"No Redundant brackets found";
	else
		cout<<"Redundant brackets found @ "<<i;
	cout<<endl;
	return 0;
}