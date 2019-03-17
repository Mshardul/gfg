#include <iostream>
#include <stack>
using namespace std;

int main(int argc, char const *argv[])
{
	string s;
	cin>>s;

	int i=0;
	stack<char> st;

	bool ans=true;

	char ch;

	do{
		ch=s[i];
		if(ch=='(' || ch=='{' || ch=='[')
			st.push(ch);
		else if(ch==')' || ch=='}' || ch==']'){
			if(!st.empty()){
				if(ch==')' && st.top()=='(')
					st.pop();
				else if(ch=='}' && st.top()=='{')
					st.pop();
				else if(ch==']' && st.top()=='[')
					st.pop();
				else{
					ans=false;
					break;
				}
			}
			else{
				ans=false;
				break;
			}
		}
	}while(s[i++]!='\0');

	if(!st.empty())
		ans=false;

	if(ans)
		cout<<"Parenthesis balanced";
	else
		cout<<"Parenthesis not balanced";
	cout<<endl;
	return 0;
}