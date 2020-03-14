#include <iostream>
using namespace std;

/*
// T(n): O(n); S(n): O(n);
void Print(int a[], int n){
	for(int i=0; i<n; i++)
		cout<<a[i]<<" ";
	cout<<endl;
}
int main(int argc, char const *argv[])
{
	int n;
	cin>>n;
	int a[n], p[n], s[n];
	for(int i=0; i<n; i++)
		cin>>a[i];
	p[0]=a[0];
	s[n-1]=a[n-1];
	for(int i=1; i<n; i++){
		p[i]=p[i-1]+a[i];
		s[n-1-i]=s[n-i]+a[n-1-i];
	}
	Print(p, n);
	Print(s, n);
	for(int i=0; i<n; i++)
		if(p[i]==s[i])
			cout<<i<<" "<<p[i]<<endl;
	return 0;
}
*/

int main(int argc, char const *argv[])
{
	int n;
	cin>>n;
	int a[n];
	for(int i=0; i<n; i++)
		cin>>a[i];
	int sum=0;
	for(int i=0; i<n; i++)
		sum+=a[i];
	int p_sum=a[0], s_sum=sum, i=0;
	do{
		if(p_sum==s_sum)
			cout<<i<<" "<<p_sum<<endl;
		p_sum+=a[i+1];
		s_sum-=a[i];
		i++;
	}while(i<n-1);
	return 0;
}
