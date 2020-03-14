#include <iostream>
#include <vector>
#include <stack>
using namespace std;

/*
//Method-1: Stack to get index of closing bracked; and vector to store these indices, so that to compare later
// T(n): O(n); S(n): O(n);
int main(int argc, char const *argv[])
{
	string s;
	cin>>s;

	int n=s.length();
	char ch;
	int i=0;
	stack<int> st;
	vector<int> vec(n);
	do{
		ch=s[i];
		if(ch=='(')
			st.push(i);
		else if(ch==')'){
			vec[st.top()]=i;
			st.pop();
		}
	}while(s[i++]!='\0');

	for(int i=0; i<n; i++)
		cout<<vec[i]<<" ";
	cout<<endl;

	int ans=0;
	for(int i=0; i<(n-1); i++){
		if(s[i]=='(' && s[i+1]=='(')
			if(vec[i]==(vec[i+1]+1))
				ans++;
	}

	cout<<ans<<endl;
	return 0;
}
*/


//without using a vector
//T(n): O(n); S(n): O(n);
int main(int argc, char const *argv[])
{
	string s;
	cin>>s;

	int n=s.length();
	char ch;
	int i=0, x;
	stack<int> st;
	do{
		ch=s[i];
		if(ch=='('){
			st.push(i);
		}
		else if(ch==')'){
			x=st.top();
			st.pop();
			if(i<n-1 && s[i+1]==')' && !st.empty() && st.top()==x-1)
				ans++;
		}
	}while(s[i++]!='\0');

	cout<<ans<<endl;
}
