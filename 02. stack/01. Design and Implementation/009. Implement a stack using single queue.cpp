#include <iostream>
#include <queue>
using namespace std;

void Display(queue<int> q){
	while(!q.empty()){
		cout<<q.front()<<" ";
		q.pop();
	}
	cout<<endl;
}
int main(int argc, char const *argv[])
{
	queue<int> q;

	int ch, ele, n=0;

	while(1){
		cout<<"1.push\t2.pop\t3.display\t";
		cin>>ch;

		if(ch==1){
			cin>>ele;
			q.push(ele);
			for(int i=0; i<n; i++){
				q.push(q.front());
				q.pop();
			}
			n++;
		}
		else if(ch==2){
			if(n==0){
				cout<<"stack is empty";
				continue;
			}
			cout<<"element popped: "<<q.front()<<endl;
			q.pop();
			n--;
		}
		else if(ch==3)
			Display(q);
		else
			break;
	}
	return 0;
}