#include <iostream>
using namespace std;

//using tournament tree, we can decrease nof comparisions. However, extra space will be required
// T(n): O(n);
int main(int argc, char const *argv[])
{
	int n;
	cin>>n;
	int a[n];
	for(int i=0; i<n; i++)
		cin>>a[i];
	int f=a[0], s=0;
	for(int i=1; i<n; i++){
		if(a[i]<f){
			s=f;
			f=a[i];
		} else if(a[i]<s && a[i]!=f){
			s=a[i];
		}
	}
	cout<<f<<" "<<s;
	return 0;
}