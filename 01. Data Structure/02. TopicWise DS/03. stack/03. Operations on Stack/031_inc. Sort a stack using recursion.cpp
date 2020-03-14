#include <iostream>
#include <stack>
using namespace std;

//pop items one by one, and apply insertion sort on pushing elements back again.
void Display(stack<int> st){
	while(!st.empty()){
		cout<<st.top()<<" ";
		st.pop();
	}
	cout<<endl;
}

void InsertEle(stack<int> st, int ele){
	cout<<"Inserting "<<ele<<endl;
	if(st.empty() || st.top()<=ele){
		st.push(ele);
		Display(st);
	}
	else{
		int x=st.top();
		st.pop();
		InsertEle(st, ele);
		st.push(x);
		Display(st);
	}
}

void Sort(stack<int> st){
	if(st.empty())
		return;
	int x=st.top();
	st.pop();
	Sort(st);
	InsertEle(st, x);
	// Display(st);
}

int main(int argc, char const *argv[])
{
	int n, temp;
	cin>>n;

	stack<int> st;
	for(int i=0; i<n; i++){
		cin>>temp;
		st.push(temp);
	}

	Sort(st);

	return 0;
}