#include <iostream>
using namespace std;

//this is the basic approach. it is good for mean, but median takes O(n log n).
//alternatively we can use rank() to get the median, making T(n) as O(n).
// T(n): O(n log n); S(n): O(1);
int main(int argc, char const *argv[])
{
	int n, a[100];
	cin>>n;
	for(int i=0; i<n; i++)
		cin>>a[i];
	int sum=0;
	for(int i=0; i<n; i++)
		sum+=a[i];
	float mean=(float)sum/n;
	sort(a, a+n);
	float median=(n%2==0)?((float)((a[n/2])+(a[n/2-1]))/2):(a[n/2]);
	cout<<"Mean = "<<mean<<" Median = "<<median<<endl;

	return 0;
}