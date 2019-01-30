#include <iostream>
#include <queue>
using namespace std;

void Display(queue<int> q){
	while(!(q.empty())){
		cout<<q.front()<<" ";
		q.pop();
	}
	cout<<endl;
}

int main(int argc, char const *argv[])
{
	int n;
	cin>>n;

	queue<int> q;
	queue<int> temp;

	int ele, ch;
	while(1){
		cout<<"1.Push\t2.Pop\t3.Print\t4.Exit\n";
		cin>>ch;

		if(ch==1){
			cin>>ele;
			if(q.size()==n)
				cout<<"Stack Overflow";
			else
				q.push(ele);
		}
		else if(ch==2){
			if(q.size()==0)
				cout<<"Stack Empty";
			else{
				while(q.size()!=1){
					temp.push(q.front());
					q.pop();
				}
				cout<<"Element popped: "<<q.front();
				q.pop();
				while(!(temp.empty())){
					q.push(temp.front());
					temp.pop();
				}
			}
		}
		else if(ch==3){
			Display(q);
		}
		else
			break;
	}
	return 0;
}