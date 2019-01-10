#include <iostream>
using namespace std;

// T(n): O(n); S(n): O(1);
int main(int argc, char const *argv[])
{
	int n, x, y;
	cin>>n;
	int a[n];
	for(int i=0; i<n; i++)
		cin>>a[i];
	cin>>x;
	cin>>y;
	int ind_x=-1, ind_y=-1, diff=INT_MAX, temp_diff;
	for(int i=0; i<n; i++){
		if(a[i]==x || a[i]==y){
			if(a[i]==x)
				ind_x=i;
			else
				ind_y=i;
			if(ind_x!=-1 && ind_y!=-1){
				temp_diff=(ind_x>ind_y)?(ind_x-ind_y):(ind_y-ind_x);
				if(temp_diff<diff)
					diff=temp_diff;
			}
		}
	}
	cout<<diff<<endl;
	return 0;
}