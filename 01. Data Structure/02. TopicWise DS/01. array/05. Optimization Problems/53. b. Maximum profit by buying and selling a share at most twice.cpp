#include <iostream>
using namespace std;

// T(n): O(n); S(n): O(1);
int main(int argc, char const *argv[])
{
	int n;
	cin>>n;
	int a[n];
	int profit[n];
	for(int i=0; i<n; i++){
		cin>>a[i];
		profit[i]=0;
	}
	int max_price=a[n-1];
	for(int i=n-2; i>=0; i--){
		if(a[i]>max_price)
			max_price=a[i];
		profit[i]=max(profit[i+1], max_price-a[i]);
	}
	int min_price=a[0];
	for(int i=1; i<n; i++){
		if(min_price>a[i])
			min_price=a[i];
		profit[i]=max(profit[i-1], profit[i]+a[i]-min_price);
	}
	cout<<profit[n-1];
	return 0;
}