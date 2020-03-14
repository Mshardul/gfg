#include <iostream>
using namespace std;

//T(n): O(n); S(n):O(1);
int main(int argc, char const *argv[])
{
	int n, k;
	cin>>n;
	cin>>k;
	int a[n];
	for(int i=0; i<n; i++)
		cin>>a[i];
	int i=0, j=0, sum=0, found=0;
	while(i<n && j<n){
		if(sum<k)
			sum+=a[i++];
		else if(sum>k)
			sum-=a[j++];
		else{
			found=1;
			cout<<j<<" "<<i-1<<endl;
			break;
		}
	}
	if(!found)
		cout<<"no such subarray found"<<endl;
	return 0;
}