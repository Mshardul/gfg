#include <iostream>
#include <stack>
using namespace std;

int main(int argc, char const *argv[])
{
	string s;
	cin>>s;

	stack<char> st;
	int i=0;
	do{
		ch=s[i];
		if(ch=='(' || ch=='{' || ch=='[')
	}while(s[i++]!='\0');
	return 0;
}