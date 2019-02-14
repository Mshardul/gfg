#include <iostream>
#include <stack>
using namespace std;

void Display(stack<int> st){
	while(!st.empty()){
		cout<<st.top()<<" ";
		st.pop();
	}
	cout<<endl;
}

int main(int argc, char const *argv[])
{
	int n;
	cin>>n;

	int a[n], b[n];
	stack<int> st;

	for(int i=0; i<n; i++)
		cin>>a[i];

	bool no=false;
	int ind=0;
	int i=1;
	while(i<=n){
		if(a[ind]==i){
			ind++;
			i++;
		}
		else if(!st.empty() && st.top()==i){
			st.pop();
			i++;
		}
		else if(!st.empty() && st.top()<a[ind]){
			no=true;
			break;
		}
		else{
			st.push(a[ind]);
			ind++;
		}
	}

	if(st.empty() && no==false)
		cout<<"Yes";
	else
		cout<<"No";
	cout<<endl;

	return 0;
}