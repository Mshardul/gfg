#include <iostream>
using namespace std;

//this is just to show that we dont need S(n)=max(a,b).
//otherwise it can be done in O(1) space;
//T(n): O(n); S(n): O(n);
int main(int argc, char const *argv[])
{
	int a, b;
	cin>>a;
	cin>>b;
	if(a>b)
		swap(a,b);
	int n=b-a+1;
	bool arr[n];
	for(int i=0; i<n; i++){
		int curr=a+i;
		if(curr%2==0 || curr%5==0)
			arr[i]=true;
	}
	for(int i=0; i<n; i++)
		if(arr[i]==true)
			cout<<a+i<<" ";
	cout<<endl;

	return 0;
}