#include <iostream>
#include <stack>
using namespace std;

int main(int argc, char const *argv[])
{
	int n;
	cin>>n;

	int a[n], nge[n];
	for(int i=0; i<n; i++)
		cin>>a[i];

	stack<int> st;

	nge[n-1]=-1;
	st.push(n-1);

	for(int i=n-2; i>-1; i--){
		while(!st.empty() && a[st.top()]<=a[i])
			st.pop();
		if(st.empty())
			nge[i]=-1;
		else
			nge[i]=st.top();
		st.push(i);
	}

	int ans[n];
	for(int i=n-1; i>-1; i--){
		if(nge[i]==-1)
			ans[i]=0;
		else{
			ans[i]=1+ans[nge[i]];
		}
	}

	for(int i=0; i<n; i++)
		cout<<ans[i]<<" ";
	cout<<endl;
	return 0;
}