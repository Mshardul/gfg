#include <iostream>
#include <stack>
using namespace std;

//T(n): O(n^2); S(n): O(n);
int main(int argc, char const *argv[])
{
	int n, temp;
	cin>>n;

	stack<int> st, st2;
	for(int i=0; i<n; i++){
		cin>>temp;
		st.push(temp);
	}

	for(int i=0 ;i<n; i++){
		for(int j=i; j>0; j--){
			st2.push(st.top());
			st.pop();
		}
		int x=st.top();
		st.pop();
		while(!st2.empty() && st2.top()>x){
			st.push(st2.top());
			st2.pop();
		}
		st.push(x);
		while(!st2.empty()){
			st.push(st2.top());
			st2.pop();
		}
	}

	while(!st.empty()){
		cout<<st.top()<<" ";
		st.pop();
	}
	cout<<endl;

	return 0;
}