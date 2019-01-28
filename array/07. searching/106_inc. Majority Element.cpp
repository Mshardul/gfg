#include <iostream>
using namespace std;

// T(n): O(n log n); S(n): O(1);
int main(int argc, char const *argv[])
{
	int n;
	cin>>n;
	int a[n];
	for(int i=0; i<n; i++)
		cin>>a[i];
	sort(a, a+n);
	int curr_ele=a[0], occ=0, curr_ind=0;
	int lim=(n/2)+1;
	int found=0;
	do{
		if(a[curr_ind+(lim-1)]==curr_ele){
			found=1;
			cout<<curr_ele<<endl;
			break;
		}
		else{
			while(a[curr_ind]==curr_ele)
				curr_ind++;
			curr_ele=a[curr_ind];
		}
	}while(curr_ind<=lim);
	if(!found)
		cout<<"no such element found"<<endl;
	return 0;
}

//using Boyer–Moore majority vote algorithm
//T(n): O(n); S(n): O(1);