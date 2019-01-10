#include <iostream>
using namespace std;

int main(int argc, char const *argv[])
{
	int n;
	cin>>n;
	int a[n];
	for(int i=0; i<n; i++)
		cin>>a[i];
	int ind=0, ans=0;
	while(ind<n){
		int i=ind;
		int cycle=0;
		while(a[i]!=i){
			int temp=a[i];
			a[i]=i;
			i=temp;
			if(!cycle){
				cycle=1;
				ans+=1;
			}
		}
		while(a[ind]==ind && ind<n){
			ind++;
		}
	}
	cout<<ans<<endl;
	return 0;
}