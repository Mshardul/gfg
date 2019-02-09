#include <iostream>
#include <stack>
using namespace std;

Reverse(stack<int> *st){
	int tp=*st.top();
	*st.pop();
	Reverse(st);
	st.push()
}

int main(int argc, char const *argv[])
{
	int n;
	cin>>n;

	stack<int> st;
	int temp;
	for(int i=0; i<n; i++){
		cin>>temp;
		st.push(temp);
	}

	Reverse(&st);
	return 0;
}