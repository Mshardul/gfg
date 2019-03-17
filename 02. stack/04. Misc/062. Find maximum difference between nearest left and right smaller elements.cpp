#include <iostream>
#include <stack>
#include <vector>
using namespace std;

//using next greater element algo
//T(n): O(n); S(n): O(n);
int main(int argc, char const *argv[])
{
	int n;
	cin>>n;

	vector<int> vec(n);
	for(int i=0; i<n; i++)
		cin>>vec[i];

	vector<int> l(n), r(n);
	stack<int> st;

	l[0]=0;
	st.push(0);
	for(int i=1; i<n; i++){
		while(!st.empty() && vec[i]<=vec[st.top()])
			st.pop();
		if(st.empty())
			l[i]=0;
		else
			l[i]=vec[st.top()];
		st.push(i);
	}

	while(!st.empty())
		st.pop();
	
	r[n-1]=0;
	st.push(n-1);
	for(int i=n-2; i>-1; i--){
		while(!st.empty() && vec[i]<=vec[st.top()])
			st.pop();
		if(st.empty())
			r[i]=0;
		else
			r[i]=vec[st.top()];
		st.push(i);
	}

	for(int i=0; i<n; i++)
		cout<<l[i]<<" "<<r[i]<<endl;

	int max_diff=INT_MIN, diff;
	for(int i=0; i<n; i++){
		if(l[i]!=-1 && r[i]!=-1){
			diff=(l[i]>r[i])?(l[i]-r[i]):(r[i]-l[i]);
			if(diff>max_diff)
				max_diff=diff;
		}
	}

	cout<<max_diff<<endl;
	return 0;
}