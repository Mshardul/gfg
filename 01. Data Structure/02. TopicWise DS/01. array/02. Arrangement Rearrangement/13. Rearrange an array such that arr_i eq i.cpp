#include <iostream>
using namespace std;

void Replace(int a[], int i){
	int temp=a[i];
	a[i]=i;
	if(temp!=-1 && temp!=i)
		return Replace(a, temp);
	return;
}
int main(int argc, char const *argv[])
{
	int n, a[1000], si=0, temp;
	cin>>n;
	for(int i=0; i<n; i++)
		cin>>a[i];
	while(si<n){
		if(a[si]==-1 || a[si]==si)
			si++;
		else{
			temp=a[si];
			a[si]=-1;
			Replace(a, temp);
		}
	}
	for(int i=0; i<n; i++)
		cout<<a[i]<<" ";
	cout<<endl;
	return 0;
}