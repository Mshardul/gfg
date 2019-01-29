#include <iostream>
using namespace std;

/*
//method 1
// T(n): O(n log n); s(n): O(1);
int main(int argc, char const *argv[])
{
	int n, x;
	cin>>n;
	int a[n];
	for(int i=0; i<n; i++)
		cin>>a[i];
	cin>>x;
	sort(a, a+n);
	int l=0, r=n-1, found=0, curr_sum;
	while(l<r){
		curr_sum=a[l]+a[r];
		if(curr_sum==x){
			found=1;
			cout<<x<<" = "<<a[l]<<" + "<<a[r];
			break;
		}
		else if(curr_sum<x)
			l++;
		else
			r--;
	}
	if(!found)
		cout<<"sum not found";
	cout<<endl;
	return 0;
}
*/

//method-2: using hashing
//T(n): O(max{a[i]}); S(n): O(n);
int main(int argc, char const *argv[])
{
	int n, x;
	cin>>n;
	int a[n];
	for(int i=0; i<n; i++)
		cin>>a[i];
	cin>>x;
	int max=a[0];
	for(int i=1; i<n; i++){
		if(max<a[i])
			max=a[i];
	}
	int b[max];
	for(int i=0; i<max; i++)
		b[i]=0;
	for(int i=0; i<n; i++)
		b[a[i]]=1;
	int ans=-1;
	for(int i=0; i<n; i++){
		if(b[x-a[i]]==1){
			ans=i;
			break;
		}
	}
	if(ans!=-1)
		cout<<x<<" = "<<a[ans]<<" + "<<x-a[ans]<<endl;
	else
		cout<<"sum not found"<<endl;
	return 0;
}