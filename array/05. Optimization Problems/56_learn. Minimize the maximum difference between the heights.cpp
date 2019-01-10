#include <iostream>
using namespace std;

//copied;
//T(n): O(n log n); S(n): O(1);
int main(int argc, char const *argv[])
{
	int n, k;
	cin>>n;
	int a[n];
	for(int i=0; i<n; i++)
		cin>>a[i];
	cin>>k;
	sort(a, a+n);
	int ans=a[n-1]-a[0]; //can not go more than this - if we increase (or decrease each element by k)
	int s=a[0];
	int l=a[n-1];
	s+=k;
	l-=k;
	if(s>l){
		int temp=s;
		s=l;
		l=temp;
	}
	for(int i=1; i<n-1; i++){
		if(a[i]+k<=l || a[i]-k>=s)
			continue;
		if(l-(a[i]-k)<=a[i]+k-s)
			s=a[i]-k;
		else
			l=a[i]+k;
	}
	cout<<min(ans, l-s);
	return 0;
}