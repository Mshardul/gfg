#include <iostream>
#include <math.h>
using namespace std;

/*
//T(n): O(n); S(n):O(1);
int main(int argc, char const *argv[])
{
	int n;
	cin>>n;
	n+=2;
	int a[n];
	for(int i=0; i<n; i++)
		cin>>a[i];
	for(int i=0; i<n; i++){
		if(a[abs(a[i])]>0)
			a[abs(a[i])]*=-1;
		else
			cout<<abs(a[i])<<endl;
	}
	return 0;
}
*/

//method2: using equations; copied
//T(n): O(n); S(n): O(1);
int main(int argc, char const *argv[])
{
	int n;
	cin>>n;
	n+=2;
	int a[n];
	for(int i=0; i<n; i++)
		cin>>a[i];
	int s=0, p=1, s_o=0, p_o=1;
	for(int i=2; i<n-1; i++)
		p_o*=i;
	for(int i=0; i<n; i++){
		p*=a[i];
		s+=a[i];
	}
	s_o=(n-2)*(n-1)/2;

	// cout<<s<<" "<<p<<" "<<s_o<<" "<<p_o<<endl;
	int x=s-s_o;
	int y=p/p_o;
	int z=sqrt(pow(x, 2) - 4*y);

	int res1=(x+z)/2;
	int res2=(abs(x-z))/2;
	cout<<res1<<" "<<res2<<endl;

	return 0;
}