#include <iostream>
using namespace std;

// T(n): O(n); S(n): O(1);
int main(int argc, char const *argv[])
{
	int n;
	cin>>n;
	int a[n];
	for(int i=0; i<n; i++)
		cin>>a[i];
	int s, e;
	for(int i=0; i<n-1; i++){
		if(a[i]>a[i+1]){
			s=i;
			break;
		}
	}
	for(int i=n-1; i>0; i--){
		if(a[i]<a[i-1]){
			e=i;
			break;
		}
	}
	int min=a[s], max=a[s];
	for(int i=s; i<=e; i++){
		if(a[i]<min)
			min=a[i];
		if(a[i]>max)
			max=a[i];
	}
	for(int i=0; i<s; i++){
		if(a[i]>min){
			s=i;
			break;
		}
	}
	for(int i=n-1; i>e; i--){
		if(a[i]<max){
			e=i;
			break;
		}
	}
	cout<<s<<" "<<e<<endl;
	return 0;
}