#include <iostream>
#include <stack>
#include <vector>
using namespace std;

//Method-1: Next greater element approach
//T(n): O(n); S(n): O(n);
int main(int argc, char const *argv[])
{
	int n;
	cin>>n;

	vector<int> vec(n);
	for(int i=0; i<n; i++)
		cin>>vec[i];

	vector<int> g(n), s(n);
	g[n-1]=-1;
	stack<int> st;
	st.push(n-1);
	for(int i=n-2; i>-1; i--){
		while(!st.empty() && vec[i]>=vec[st.top()])
			st.pop();
		if(st.empty())
			g[i]=-1;
		else
			g[i]=st.top();
		st.push(i);
	}

	while(!st.empty())
		st.pop();
	s[n-1]=-1;
	st.push(n-1);
	for(int i=n-2; i>-1; i--){
		while(!st.empty() && vec[i]<=vec[st.top()])
			st.pop();
		if(st.empty())
			s[i]=-1;
		else
			s[i]=st.top();
		st.push(i);
	}

	for(int i=0; i<n; i++)
		cout<<g[i]<<" ";
	cout<<endl;
	for(int i=0; i<n; i++)
		cout<<s[i]<<" ";
	cout<<endl;

	for(int i=0; i<n; i++){
		if(g[i]==-1 || s[g[i]]==-1)
			cout<<-1;
		else
			cout<<vec[s[g[i]]];
		cout<<" ";
	}
	cout<<endl;
	return 0;
}