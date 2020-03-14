//use stack for operators, and vector for storing final answer
//traverse from l to r
//on getting an operand, push into the vector
//on getting a operator
	//if pop from stack and push into vector untill a lower priority operator is found

#include <iostream>
#include <stack>
#include <iterator>
#include <vector>
using namespace std;

int main(int argc, char const *argv[])
{
	stack<int> s;
	char ch, lst_op;
	vector<char> c;

	while(1){
		cin>>ch;
		if(ch=='+' || ch=='-'){
			while(!s.empty()){
				c.push_back(s.top());
				s.pop();
			}
			s.push(ch);	
		}
		else if(ch=='*' || ch=='/'){
			while(!(s.empty()) && (s.top()=='*' || s.top()=='/')){
				c.push_back(s.top());
				s.pop();
			}
			s.push(ch);
		}
		else if(ch==';'){
			while(!(s.empty())){
				c.push_back(s.top());
				s.pop();
			}
			break;
		}
		else{
			c.push_back(ch);
		}
	}
	vector<char>::iterator it;
	for(it=c.begin(); it!=c.end(); it++)
		cout<<*it<<" ";
	cout<<endl;
	return 0;
}