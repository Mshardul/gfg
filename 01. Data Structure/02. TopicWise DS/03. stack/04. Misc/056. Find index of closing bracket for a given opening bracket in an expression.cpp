#include <iostream>
#include <stack>
using namespace std;

int main(int argc, char const *argv[])
{
	string s;
	cin>>s;

	int ind;
	cin>>ind;

	int i=0;
	stack<int> st;
	char ch;
	do{
		ch=s[i];
		if(ch=='('){
			st.push(i);
		}
		else if(ch==')'){
			if(st.top()==ind){
				cout<<i<<endl;
				break;
			}
			else{
				st.pop();
			}
		}
	}while(s[i++]!='\0');
	return 0;
}