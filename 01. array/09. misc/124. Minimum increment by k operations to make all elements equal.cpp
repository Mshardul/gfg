#include <iostream>
using namespace std;

int main(int argc, char const *argv[])
{
	int n, k;
	cin>>n;
	cin>>k;

	int a[n];
	for(int i=0; i<n; i++)
		cin>>a[i];

	int max=a[0];
	for(int i=1; i<n; i++){
		if(a[i]>max)
			max=a[i];
	}

	int ans=0;
	for(int i=0; i<n; i++){
		int steps=(max-a[i])/k;
		if(steps*k==(max-a[i]))
			ans+=steps;
		else{
			ans=-1;
			break;
		}
	}

	cout<<ans<<endl;

	return 0;
}