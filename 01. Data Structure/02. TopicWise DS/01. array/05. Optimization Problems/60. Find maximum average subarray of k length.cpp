#include <iostream>
using namespace std;

// T(n): O(n); S(n): O(1);
int main(int argc, char const *argv[])
{
	int n, k, i;
	cin>>n;
	int a[n];
	for(i=0; i<n; i++)
		cin>>a[i];
	cin>>k;
	int curr_sum=0, max_sum;
	for(i=0; i<k; i++)
		curr_sum+=a[i];
	max_sum=curr_sum;
	while(i<n){
		curr_sum+=(a[i]-a[i-k]);
		if(curr_sum>max_sum)
			max_sum=curr_sum;
		i++;
	}
	cout<<((float)max_sum/k);
	return 0;
}