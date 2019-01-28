#include <iostream>
using namespace std;

/*
// T(n): O(n); S(n): O(n);
int main(int argc, char const *argv[])
{
	int n;
	cin>>n;
	int a[n], b[n], ans;
	for(int i=0; i<n; i++)
		cin>>a[i];
	for(int i=0; i<n; i++)
		b[i]=0;
	for(int i=0; i<n; i++){
		if(b[a[i]]==0)
			b[a[i]]=1;
		else{
			ans=a[i];
			break;
		}
	}
	cout<<ans<<endl;
	return 0;
}
*/

/*
//T(n): O(n); S(n): O(1);
int main(int argc, char const *argv[])
{
	int n;
	cin>>n;
	int a[n];
	for(int i=0; i<n; i++)
		cin>>a[i];
	int sum=0;
	for(int i=1; i<n+1; i++)
		sum+=i;
	for(int i=0; i<n; i++)
		sum-=a[i];
	cout<<n-sum<<endl;
	return 0;
}
*/

//using indexing - copied
// T(n): O(n); S(n): O(1);
int main(int argc, char const *argv[])
{
	int n, found;
	cin>>n;
	int a[n];
	for(int i=0; i<n; i++)
		cin>>a[i];
	for(int i=0; i<n; i++){
		int ind=(a[i]>-1)?1:-1;
		ind*=a[i];
		if(a[ind]>-1)
			a[ind]*=-1;
		else{
			found=ind;
			break;
		}
	}
	cout<<found<<endl;
	return 0;
}