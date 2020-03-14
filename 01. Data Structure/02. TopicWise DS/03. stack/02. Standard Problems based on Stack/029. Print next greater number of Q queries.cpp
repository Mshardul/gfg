#include <iostream>
#include <stack>
using namespace std;

int main(int argc, char const *argv[])
{
	int n;
	cin>>n;

	int a[n];
	for(int i=0; i<n; i++)
		cin>>a[i];
	
	int ans[n];
	stack<int> st;

	ans[n-1]=-1;
	st.push(n-1);
	
	for(int i=n-2; i>-1; i--){
		while(!st.empty() && a[st.top()]<=a[i])
			st.pop();
		if(st.empty())
			ans[i]=-1;
		else
			ans[i]=st.top();
		st.push(i);
	}

	int m, ind;
	cin>>m;

	for(int i=0; i<m; i++){
		cin>>ind;
		if(ans[ind]==-1)
			cout<<-1;
		else
			cout<<a[ans[ind]];
		cout<<endl;
	}
	return 0;
}