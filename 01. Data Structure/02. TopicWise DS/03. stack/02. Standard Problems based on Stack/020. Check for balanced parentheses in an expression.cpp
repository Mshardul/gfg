#include <iostream>
#include <stack>
using namespace std;

// T(n): O(n); S(n): O(n);
int main(int argc, char const *argv[])
{
	char ch;
	int ans=1;
	stack<char> s;
	do{
		cin>>ch;
		if(ch=='(' || ch=='{' || ch=='[')
			s.push(ch);
		else if(ch==')'){
			if(s.top()=='(')
				s.pop();
			else{
				ans=0;
				break;
			}
		}
		else if(ch=='}'){
			if(s.top()=='{')
				s.pop();
			else{
				ans=0;
				break;
			}
		}
		else if(ch==']'){
			if(s.top()=='[')
				s.pop();
			else{
				ans=0;
				break;
			}
		}
	}while(ch!=';');
	if(ans && s.empty())
		cout<<"YES!!\n";
	else
		cout<<"NO!!\n";
	return 0;
}