#include <iostream>
#include <stack>
using namespace std;

//replace balanced opening and closed prenthesis with 0, 1 respectively
//replace unbalanced parentheses with -
int main(int argc, char const *argv[])
{
	string s;
	cin>>s;

	stack<int> st;

	int i=0;
	char ch;
	int ind=0;
	do{
		ch=s[i];
		if(ch=='('){
			st.push(i);
		}
		else if(ch==')'){
			if(!st.empty()){
				s[st.top()]='0';
				s[i]='1';
				st.pop();
			}
			else{
				s[i]='-';
			}
		}
	}while(s[i++]!='\0');

	while(!st.empty()){
		s[st.top()]='-';
		st.pop();
	}

	cout<<s<<endl;
	return 0;
}