#include <iostream>
using namespace std;

//this is the kadane's algo
// T(n): O(n); S(n): O(1);
int main(int argc, char const *argv[])
{
	int n;
	cin>>n;
	int a[n];
	for(int i=0; i<n; i++)
		cin>>a[i];
	int max_sum=INT_MIN, curr_sum=0, temp_l=0, l, r;
	for(int i=0; i<n; i++){
		curr_sum+=a[i];
		if(curr_sum>max_sum){
			max_sum=curr_sum;
			l=temp_l;
			r=i;
		}
		if(curr_sum<0){
			temp_l=i+1;
			curr_sum=0;
		}
	}
	cout<<max_sum<<endl;
	for(int i=l; i<=r; i++)
		cout<<a[i]<<" ";
	cout<<endl;
	return 0;
}