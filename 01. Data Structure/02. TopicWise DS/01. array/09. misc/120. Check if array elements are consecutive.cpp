#include <iostream>
using namespace std;

/*
T(n): O(n log n); S(n): O(1);
int main(int argc, char const *argv[])
{
	int n;
	cin>>n;
	int a[n];
	for(int i=0; i<n; i++)
		cin>>a[i];
	sort(a, a+n);

	int yes=1;
	for(int i=1; i<n; i++)
		if(a[i]!=a[i-1]+1)
			yes=0;
	if(yes)
		cout<<"Array elements are consecutive";
	else
		cout<<"Array elements are not consecutive";
	cout<<endl;
	return 0;
}
*/

/*
//T(n): O(n); S(n): O(n);
int main(int argc, char const *argv[])
{
	int n;
	cin>>n;
	int a[n];
	for(int i=0; i<n; i++)
		cin>>a[i];

	int min=a[0];
	for(int i=1; i<n; i++)
		if(a[i]<min)
			min=a[i];

	int yes=1;

	int b[n];
	for(int i=0; i<n; i++)
		b[i]=0;
	for(int i=0; i<n; i++){
		if(b[a[i]-min]!=0){
			yes=0;
			break;
		}
		b[a[i]-min]++;
	}

	if(yes)
		cout<<"Array elements are consecutive";
	else
		cout<<"Array elements are not consecutive";
	cout<<endl;

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

	int min=a[0];
	for(int i=1; i<n; i++)
		if(a[i]<min)
			min=a[i];

	int yes=1;

	for(int i=0; i<n; i++){
		int ele=abs(a[i]);
		int ind=ele-min;
		if(a[ind]<0){
			yes=0;
			break;
		}
		a[ind]*=-1;
	}
	
	if(yes)
		cout<<"Array elements are consecutive";
	else
		cout<<"Array elements are not consecutive";
	cout<<endl;

	
	return 0;
}