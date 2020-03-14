#include <iostream>
#include <stack>
using namespace std;

/*
//Method 1: using stack;
//T(n): O(n); S(n): O(n)
int main(int argc, char const *argv[])
{
	string s;
	getline(cin, s);

	stack<char> st;
	int i=0;
	do{
		st.push(s[i]);
		i++;
	}while(s[i]!='\0');

	while(!st.empty()){
		cout<<st.top();
		st.pop();
	}

	return 0;
}
*/

//Method 2: swapping characters
//T(n): O(n); S(n): O(1);
int main(int argc, char const *argv[])
{
	string s;
	getline(cin, s);

	int n=s.length();
	cout<<n;
	
	return 0;
}