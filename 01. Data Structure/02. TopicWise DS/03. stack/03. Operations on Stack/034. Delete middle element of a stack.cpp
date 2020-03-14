#include <iostream>
#include <stack>
using namespace std;


//using temporary stack
//T(n): O(n); S(n): O(n)

void Display(stack<int> temp){
	while(!temp.empty()){
		cout<<temp.top()<<" ";
		temp.pop();
	}
	cout<<endl;
}

int main(int argc, char const *argv[])
{
	int n, temp;
	cin>>n;

	stack<int> st, st2;

	for(int i=0; i<n; i++){
		cin>>temp;
		st.push(temp);
	}

	int noOfEle=0;
	while(!st.empty()){
		st2.push(st.top());
		st.pop();
		noOfEle++;
	}

	noOfEle/=2;
	while(noOfEle>0){
		st.push(st2.top());
		st2.pop();
		noOfEle--;
	}
	st2.pop();
	while(!st2.empty()){
		st.push(st2.top());
		st2.pop();
	}

	Display(st);
	return 0;
}