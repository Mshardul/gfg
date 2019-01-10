#include <iostream>
using namespace std;

// T(n) = O(n); S(n) = O(1)
int main(int argc, char const *argv[])
{
	int n, a[1000], sum=0, max=0, temp, curr;
	cin>>n;
	for(int i=0; i<n; i++){
		cin>>temp;
		sum+=temp;
		a[i]=temp;
		max+=i*temp;
	}
	curr=max;
	for(int i=1; i<n; i++){
		curr=curr-sum+(n*a[i-1]);
		if(curr>max)
			max=curr;
	}
	cout<<max<<endl;
	return 0;
}