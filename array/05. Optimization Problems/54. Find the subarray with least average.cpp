#include <iostream>
using namespace std;

int main(int argc, char const *argv[])
{
	int n, k, i;
	cin>>n;
	int a[n];
	for(i=0; i<n; i++)
		cin>>a[i];
	cin>>k;
	int curr_sum=0, min_sum, ind=0;
	for(i=0; i<k; i++)
		curr_sum+=a[i];
	min_sum=curr_sum;
	while(i<n){
		curr_sum+=(a[i]-a[i-k]);
		if(curr_sum<min_sum){
			ind=i-k+1;
			min_sum=curr_sum;
		}
		i++;
	}
	for(i=0; i<k; i++)
		cout<<a[ind+i]<<" ";
	cout<<endl<<((float)min_sum/k)<<endl;
	return 0;
}