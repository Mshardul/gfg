#include <iostream>
#include <stack>
#include <queue>
using namespace std;

void DisplayQueue(queue<int> q){
	while(!q.empty()){
		cout<<q.front()<<" ";
		q.pop();
	}
	cout<<endl;
}

void DisplayStack(stack<int> st){
	while(!st.empty()){
		cout<<st.top()<<" ";
		st.pop();
	}
	cout<<endl;
}
int main(int argc, char const *argv[])
{
	int n, temp;
	cin>>n;

	stack<int> st;
	queue<int> q;
	for(int i=0; i<n; i++){
		cin>>temp;
		q.push(temp);
	}

	DisplayQueue(q);

	int i=1, no=0;
	while(i<=n){
		if(!q.empty() && q.front()==i){
			q.pop();
			i++;
		}
		else if(!st.empty() && st.top()==i){
			st.pop();
			i++;
		}
		else{
			if(!st.empty() && (st.top() < q.front())){
				no=true;
				break;
			}
			st.push(q.front());
			q.pop();
		}
	}

	DisplayStack(st);

	if(st.empty() && no==0)
		cout<<"Yes";
	else
		cout<<"No";
	cout<<endl;
	return 0;
}