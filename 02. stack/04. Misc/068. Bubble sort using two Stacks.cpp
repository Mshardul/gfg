#include <iostream>
#include <stack>

using namespace std;

int main(int argc, char const *argv[])
{
	int n;
	cin>>n;

	int temp;
	stack<int> st1;
	stack<int> st2;

	for(int i=0; i<n; i++){
		cin>>temp;
		st1.push(temp);
	}

	while(!st1.empty()){
		st2.push(st1.top());
		st1.pop();
	}

	for(int i=0; i<n; i++){
		
		while(!st2.empty()){
			if(st1.empty()){
				st1.push(st2.top());
				st2.pop();
			}
			else if(st1.top()<=st2.top()){
				st1.push(st2.top());
				st2.pop();
			}
			else{
				temp=st1.top();
				st1.pop();
				st1.push(st2.top());
				st2.pop();
				st1.push(temp);
			}
		}
		while(!st1.empty()){
			st2.push(st1.top());
			st1.pop();
		}
	}

	while(!st2.empty()){
		cout<<st2.top()<<" ";
		st2.pop();
	}
	cout<<endl;
	
	return 0;
}