#include <iostream>
#include <stack>
using namespace std;

/*
//brute force
//T(n): O(n^2); S(n): O(1);
int main(int argc, char const *argv[])
{
	int n;
	cin>>n;

	int a[n];
	for(int i=0; i<n; i++)
		cin>>a[i];

	for(int i=0; i<n; i++){
		int ans=0;
		for(int j=i; j>-1; j--){
			if(a[j]<=a[i])
				ans++;
			else
				break;
		}
		cout<<ans<<" ";
	}
	cout<<endl;
	return 0;
}
*/

/*
//one stack to maintain indices of array integers in decreasing sequence
//for each integer in the array, pop indices which are smaller than current integer
//push this current integer
//T(n): O(n); S(n): O(n);
int main(int argc, char const *argv[])
{
	int n;
	cin>>n;

	int a[n];
	for(int i=0; i<n; i++)
		cin>>a[i];

	stack<int> st;
	st.push(0);

	int arr[n];
	arr[0]=1; 

	for(int i=1; i<n; i++){
		while(!st.empty() && (a[st.top()]<=a[i]))
			st.pop();
		if(st.empty())
			cout<<i+1;
		else
			cout<<i-st.top();
		cout<<" ";
		st.push(i);
	}
	cout<<endl;

	return 0;
}
*/