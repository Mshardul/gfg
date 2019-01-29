#include <iostream>
using namespace std;

int main(int argc, char const *argv[])
{
	int n, x;
	cin>>n;
	int a[n];
	for(int i=0; i<n; i++)
		cin>>a[i];
	cin>>x;
	int l=0, r=n-1, done=0;
	while(l<=r){
		int sum=a[l]+a[r];
		if(sum==x){
			done=1;
			break;
		}
		else if(sum>x)
			r--;
		else
			l++;
	}
	done?cout<<"True":cout<<"False";
	cout<<endl;
	return 0;
}