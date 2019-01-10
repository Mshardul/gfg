#include <iostream>
using namespace std;

//might be wrong, but seems okay. //definitely not.
//not on geeks. do verify and contribute if ok.
//ans=max((a[n-k]+b[n-1]), (a[n-k+1]+b[n-2]),...(a[n-1]+b[n-k]))
//T(n): O(n-k) for sorted array. otherwise O(n log n);
//S(n): O(1);
int main(int argc, char const *argv[])
{
	int n, k, i, max=0, temp;
	cin>>n;
	int a[100], b[100];
	for(i=0; i<n; i++){
		cin>>a[i];
		cin>>b[i];
	}
	cin>>k;
	sort(a, a+n);
	sort(b, b+n);
	i=0;

	while(i<k){
		temp=a[n-k+i]+b[n-1-i];
		if(temp>max)
			max=temp;
		i++;
	}
	cout<<max;

	return 0;
}