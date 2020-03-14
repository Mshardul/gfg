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

	stack<int> st;

	int l[n];
	l[n-1]=0;
	st.push(n-1);

	for(int i=n-2; i>-1; i--){
		while(!st.empty() && a[st.top()]<=a[i])
			st.pop();
		if(st.empty())
			l[i]=0;
		else
			l[i]=st.top()+1;
		st.push(i);
	}

	while(!st.empty())
		st.pop();

	int r[n];
	r[0]=0;
	st.push(0);

	for(int i=1; i<n; i++){
		while(!st.empty() && a[st.top()]<=a[i])
			st.pop();
		if(st.empty())
			r[i]=0;
		else
			r[i]=st.top()+1;
		st.push(i);
	}

	for(int i=0; i<n; i++){
		// cout<<i<<": "<<l[i]<<" "<<r[i]<<endl;
		cout<<l[i]*r[i]<<" ";
	}
	cout<<endl;
	return 0;
}