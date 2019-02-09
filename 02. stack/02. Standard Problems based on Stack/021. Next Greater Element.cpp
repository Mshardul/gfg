#include <iostream>
#include <stack>
using namespace std;

//T(n): O(n); S(n): O(n);
int main(int argc, char const *argv[])
{
	int n;
	cin>>n;

	int a[n];
	for(int i=0; i<n; i++)
		cin>>a[i];

	stack<int> s;
	s.push(n-1);

	int ans[n];

	ans[n-1]=-1;

	for(int i=n-2; i>-1; i--){
		while(!s.empty() && (a[s.top()]<=a[i]))
			s.pop();
		if(s.empty())
			ans[i]=-1;
		else
			ans[i]=a[s.top()];
		s.push(i);
	}

	for(int i=0; i<n; i++)
		cout<<ans[i]<<" ";
	cout<<endl;

	return 0;
}