#include <iostream>
using namespace std;

int main(int argc, char const *argv[])
{
	int n, a[1000], q, x, y, si=0;
	cin>>n;
	for(int i=0; i<n; i++)
		cin>>a[i];
	while(1){
		cin>>q;
		if(q==1){
			cin>>x;
			si-=x;
			if(si<0)
				si+=n;
		}
		else if(q==2){
			cin>>y;
			si+=y;
			if(si>=n)
				si=si%n;
		}
		else if(q==3){
			cin>>x>>y;
			int sum=0;
			for(int i=si+x; i<=si+y; i++)
				sum+=a[i%n];
			cout<<sum<<endl;
		}
		else
			break;
	}
	return 0;
}