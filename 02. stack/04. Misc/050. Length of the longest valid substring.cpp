#include <iostream>
#include <stack>
#include <string>
using namespace std;

int main(int argc, char const *argv[])
{
	string s;
	cin>>s;

	int l_ind=0;
	do{
		if(l_ind==')')
			l_ind++;
		else 
			break;
	}while(s[l_ind]!='\0');

	int r_ind=(s.length())-1;
	do{
		if(r_ind=='(')
			r_ind--;
		else
			break;
	}while(s[r_ind]!='\0');

	int n=0, max=0;
	stack<char> st;
	while(l_ind<=r_ind){
		if(s[l_ind]=='(')
			st.push(s[l_ind]);
		else if(s[l_ind]==')'){
			if(!st.empty() && st.top()=='('){
				st.pop();
				n++;
				if(n>max)
					max=n;
			}
			else
				n=0;
		}
		l_ind++;
	}
	cout<<(2*max)<<endl;
	return 0;
}