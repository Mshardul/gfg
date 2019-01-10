#include <iostream>
using namespace std;

// T(n): O(n); S(n): O(1);
int main(int argc, char const *argv[])
{
	int t;
	cin>>t;
	while(t-->0){
		int n, a[100], tot_ele=0, k;
		cin>>n;
		for(int i=0; i<n; i++)
			cin>>a[i];
		cin>>k;
		for(int i=0; i<n; i++){
			if(a[i]<=k)
				tot_ele++;
		}
		int i;
		int max_ele, curr_ele=0;
		for(i=0; i<tot_ele; i++){
			if(a[i]<=k)
				curr_ele++;
		}
		max_ele=curr_ele;
		while(i<n){
			if(a[i-tot_ele]<=k)
				curr_ele--;
			if(a[i]<=k)
				curr_ele++;
			if(curr_ele>max_ele)
				max_ele=curr_ele;
			// cout<<i<<" "<<curr_ele<<endl;
			i++;
		}
		cout<<tot_ele-max_ele<<endl;
	}

	return 0;
}