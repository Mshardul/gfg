#include <iostream>
#include <stack>
using namespace std;

//T(n): O(n); S(n): O(n);
int main(int argc, char const *argv[])
{
	string s;
	cin>>s;

	char ch;
	stack<char> st;
	int i=0, ans=0;
	do{
		ch=s[i];
		if(ch=='{')
			st.push(ch);
		else if(ch=='}'){
			if(!st.empty())
				st.pop();
			else{
				ans++;
				st.push('{');
			}
		}
	}while(s[++i]!='\0');

	int n=0;
	while(!st.empty()){
		n++;
		st.pop();
	}
	
	if(n%2==1)
		cout<<"not possible\n";
	else
		cout<<(ans)+(n/2)<<endl;
	return 0;
}