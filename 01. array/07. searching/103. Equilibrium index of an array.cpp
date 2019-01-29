#include <iostream>
using namespace std;

// T(n): O(n); S(n): O(1);
int main(int argc, char const *argv[])
{
	int n;
	cin>>n;
	int a[n];
	for(int i=0; i<n; i++)
		cin>>a[i];
	int sum=0;
	for(int i=0; i<n; i++)
		sum+=a[i];
	int p_sum=0, s_sum=sum-a[0], i=0;
	do{
		if(p_sum==s_sum)
			cout<<i<<endl;
		p_sum+=a[i];
		s_sum-=a[i+1];
		i++;
	}while(i<n-1);
	return 0;
}