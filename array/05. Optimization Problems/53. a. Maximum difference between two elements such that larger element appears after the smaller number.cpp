#include <iostream>
using namespace std;

/*
//subtract each element with min element in its left subarray
//similarly, we can subtract max element in its right subarray with each number
//T(n): O(n); S(n):O(1);
int main(int argc, char const *argv[])
{
	int n;
	cin>>n;
	int a[n];
	for(int i=0; i<n; i++)
		cin>>a[i];
	int min=a[0];
	int diff=INT_MIN;
	for(int i=0; i<n; i++){
		if(a[i]<min)
			min=a[i];
		else if((a[i]-min)>diff)
			diff=a[i]-min;
	}
	cout<<diff<<endl;
	return 0;
}
*/

// we can also get the diff among adjacent elements. and then get max-sum subarray in this new array.
// T(n): O(n); S(n): O(1);
int main(int argc, char const *argv[])
{
	int n;
	cin>>n;
	int a[n];
	for(int i=0; i<n; i++)
		cin>>a[i];
	for(int i=n-1; i>0; i--)
		a[i]-=a[i-1];
	// a[0]=0;
	int max_sum, curr_sum=0;
	for(int i=1; i<n; i++){ //a[0] should not be counted, as we already got its difference
		curr_sum+=a[i];
		if(curr_sum>max_sum)
			max_sum=curr_sum;
		if(curr_sum<0)
			curr_sum=0;
	}
	cout<<max_sum<<endl;
	return 0;
}