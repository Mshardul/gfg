#include <iostream>
#include <stack>
using namespace std;

//T(n): O(n^2); S(n): O(n);
int main(int argc, char const *argv[])
{
	int n;
	cin>>n;

	int a[n];
	for(int i=0; i<n; i++)
		cin>>a[i];

	stack<int> st;

	for(int i=0; i<n; i++){
		int x=a[i];
		int j=i-1;
		while(j>-1 && a[j]>x){
			st.push(a[j]);
			j--;
		}
		st.push(x);
		while(j>-1){
			st.push(a[j]);
			j--;
		}
		j=0;
		while(j<=i){
			a[j]=st.top();
			st.pop();
			j++;
		}
		cout<<i<<": ";
		for(int k=0; k<n; k++)
			cout<<a[k]<<" ";
		cout<<endl;
	}
	return 0;
}