#include <iostream>
using namespace std;

//using kadane's approach
//T(n)=O(kn); S(n)=O(n);
void Print(int a[], int n){
	for(int i=0; i<n; i++)
		cout<<a[i]<<" ";
	cout<<endl;
}
int main(int argc, char const *argv[])
{
	int n, a[100], k;
	cin>>n;
	for(int i=0; i<n; i++)
		cin>>a[i];
	cin>>k;
	while(k-->0){
		int max=-101, curr_max=0, l, r, temp_l=0;
		for(int i=0; i<n; i++){
			curr_max+=a[i];
			if(curr_max>max){
				max=curr_max;
				r=i;
				l=temp_l;
			}
			if(curr_max<0){
				curr_max=0;
				temp_l=i+1;
			}
		}
		cout<<l<<" "<<r<<endl;
		for(int i=l; i<=r; i++)
			a[i]=-100;// a[i]=INT_MIN;
		Print(a, n);
	}
	return 0;
}