#include <iostream>
#include <stack>
using namespace std;

//wont run, as DoesKnow() is not defined;
//T(n): O(n); S(n): O(n);
int main(int argc, char const *argv[])
{
	int n;
	cin>>n;

	bool ans[n];
	stack<char> st;
	char ch, ch2;

	for(int i=0; i<n; i++){
		cin>>ch;
		st.puch(ch);
	}

	while(!(st.empty())){
		ch=st.top();
		st.pop();
		if(st.empty())
			break;
		ch2=st.top();
		st.pop();

		if(DoesKnow(ch, ch2)) //ch knows ch2
			st.push(ch2);
		else
			st.push(ch);
	}

	cout<<ch<<endl;

	return 0;
}