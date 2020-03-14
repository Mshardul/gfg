#include <iostream>
using namespace std;

int pow(int a, int b){
	if(b==0)
		return 1;
	if(b==1)
		return a;
	if(b%2==1)
		return a*pow(a*a, b/2);
	return pow(a*a, b/2);
}
int main(int argc, char const *argv[])
{
	int n;
	cin>>n;
	int a[n];
	for(int i=0; i<n; i++)
		cin>>a[i];
	int min_double=INT_MAX, curr_double=0;
	for(int i=0; i<n; i++){
		int m=a[i];
		while(m>1){
			m/=2;
			curr_double++;
		}
		if(min_double>curr_double)
			min_double=curr_double;
	}
	cout<<min_double<<endl;
	int res=min_double+n;
	for(int i=0; i<n; i++){
		res+=a[i]-pow(2, min_double);
	}
	cout<<res<<endl;
	return 0;
}