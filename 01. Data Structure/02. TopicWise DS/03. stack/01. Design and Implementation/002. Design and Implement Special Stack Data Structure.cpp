#include <iostream>
#include <stack>
using namespace std;

//space can be optimized, if elements entry in stack are unique
//T(n): O(n); S(n): O(n);
void Display(stack<int> s){
	while(!(s.empty())){
		cout<<s.top()<<" ";
		s.pop();
	}
	cout<<endl;
}

int main(int argc, char const *argv[])
{
	int n;
	cin>>n;

	stack<int> s;
	stack<int> min;

	int minEle=INT_MAX;
	int oper, ele;

	while(1){
		cout<<"1.push\t2.pop\t3.print\t4.min\t5.exit\n";
		cin>>oper;

		if(oper==1){
			cin>>ele;
			if(s.size()==n)
				cout<<"Stack Overflow";
			else{
				if(minEle>ele)
					minEle=ele;
				s.push(ele);
				min.push(minEle);
			}
		}
		else if(oper==2){
			if(s.size()==0)
				cout<<"Empty Stack";
			else{
				cout<<"Element popped"<<s.top();
				s.pop();
				min.pop();
			}
		}
		else if(oper==3)
			Display(s);
		else if(oper==4)
			cout<<min.top();
		else
			break;
	}
	return 0;
}