#include <iostream>
#include <stack>
using namespace std;

void Display(stack<int> temp){
	while(!temp.empty()){
		cout<<temp.top()<<" ";
		temp.pop();
	}
	cout<<endl;
}

int main(int argc, char const *argv[])
{
	stack<int> s;
	int temp, minEle, ch, ele=0;

	cin>>temp;

	s.push(temp);
	minEle=temp;
	
	while(1){
		cout<<"1.push\t2.pop\t3.minEle\t4.Display:\t";
		cin>>ch;
		if(ch==1){
			ele++;
			cin>>temp;
			if(temp>minEle)
				s.push(minEle);
			else{
				s.push(2*temp-minEle);
				minEle=temp;
			}
		}
		else if(ch==2){
			if(ele==0){
				cout<<"Stack is empty";
				continue;
			}
			cout<<"element popped: ";
			if(s.top()>minEle)
				cout<<s.top();
			else if(s.top()<minEle){
				cout<<minEle;
				minEle=((2*minEle)-s.top());
			}
			else
				cout<<minEle;
			s.pop();
			cout<<endl;
		}
		else if(ch==3)
			cout<<"min element: "<<minEle<<endl;
		else if(ch==4)
			Display(s);
		else
			break;
	}



	return 0;
}