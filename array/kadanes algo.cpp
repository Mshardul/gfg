#include <iostream>
using namespace std;

int main(int argc, char const *argv[])
{
	int n, a[100], curr_sum=0, max=0;
	cin>>n;
	for(int i=0; i<n; i++)
		cin>>a[i];
	// curr_sum=a[0];
	for(int i=0; i<n-1; i++){
		curr_sum+=a[i];
		if(curr_sum<0)
			curr_sum=0;
		else if(max<curr_sum)
			max=curr_sum;
	}
	cout<<max;
	return 0;
}