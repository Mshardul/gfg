#include <iostream>
#include <stack>
using namespace std;

//assuming parenthesis sequence to be balanced.
int main(int argc, char const *argv[])
{
	string s;
	cin>>s;

	stack<int> st;
	int i=0, n=0, max=0;
	do{
		if(s[i]=='('){
			st.push(1);
			n++;
			if(n>max){
				max=n;
			}
		}
		else if(s[i]==')'){
			n--;
			st.pop();
		}
	}while(s[i++]!='\0');
	cout<<max<<endl;
	return 0;
}