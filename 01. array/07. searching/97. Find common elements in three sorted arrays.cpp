#include <iostream>
using namespace std;

int main(int argc, char const *argv[])
{
	int m, n, o;
	cin>>m;
	cin>>n;
	cin>>o;
	int a[m], b[n], c[o];
	for(int i=0; i<m; i++)
		cin>>a[i];
	for(int i=0; i<n; i++)
		cin>>b[i];
	for(int i=0; i<o; i++)
		cin>>c[i];
	int j=0, k=0, l=0;
	while(j<m && k<n && l<o){
		if((a[j]==b[k])&&(b[k]==c[l])){
			cout<<a[j++]<<" ";
			k++;
			l++;
			continue;
		}
		int min_ele=min(min(a[j], b[k]), c[l]);
		if(min_ele==a[j])
			j++;
		if(min_ele==b[k])
			k++;
		if(min_ele==c[l])
			l++;
	}
	return 0;
}