#include <iostream>
#include <stack>
#include <stdlib.h>
using namespace std;

//using stack;
//T(n): O(n); S(n): O(n);
void Display(stack<char> st){
	while(!st.empty()){
		cout<<st.top()<<" ";
		st.pop();
	}
	cout<<endl;
}

int main(int argc, char const *argv[])
{
	string s, out;
	getline(cin, s);
	stack<char> st;

	char ch=s[0];
	for(int i=0; s[i]!=';'; i++){
		if(s[i]==' '){
			while(!st.empty()){
				out+=st.top();
				st.pop();
			}
			out+=' ';
		}
		else
			st.push(s[i]);
	}
	while(!st.empty()){
		out+=st.top();
		st.pop();
	}

	cout<<out<<endl;
	return 0;
}