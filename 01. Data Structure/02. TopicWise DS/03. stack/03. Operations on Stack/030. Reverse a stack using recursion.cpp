#include <iostream>
#include <stack>
using namespace std;

//for each insertion, pop all items, and push new item(to be pushed) at the bottom, and then pushing all the popped elements.
//T(n): O(n^2); S(n): O(1);
void InsertAtLast(stack<int> st, int x){
	if(st.empty())
		st.push(x);
	else{
		int y=st.top();
		st.pop();
		InsertAtLast(st, y);
		st.push(y);
	}
}

void Reverse(stack<int> st){
	if(st.empty())
		return;
	int x=st.top();
	st.pop();
	Reverse(st);
	InsertAtLast(st, x);
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

	Reverse(st);

	for(int i=0; i<n; i++){
		cout<<st.top()<<" ";
		st.pop();
	}
	cout<<endl;
	
	return 0;
}