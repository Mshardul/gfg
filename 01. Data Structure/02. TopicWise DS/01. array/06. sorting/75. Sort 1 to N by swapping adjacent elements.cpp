#include <iostream>
using namespace std;

int main(int argc, char const *argv[])
{
	int n;
	cin>>n;
	int a[n], b[n];
	for(int i=0; i<n; i++)
		cin>>a[i];
	for(int i=0; i<n-1; i++)
		cin>>b[i];
	for(int i=0; i<n; i++)
		for(int j=0; j<n; j++)
	for(int i=0; i<n-1; i++){
		int ind=0;
		while(b[i+ind]){
			ind++;
		}
		sort(a+i, a+i+ind+1);
		i+=ind;
	}
	int sorted=1;
	for(int i=0; i<n; i++){
		if(a[i]>a[i+1]){
			sorted=0;
			break;
		}
	}
	if(sorted)
		cout<<"Array can be sorted"<<endl;
	else
		cout<<"Array cannot be sorted"<<endl;
}