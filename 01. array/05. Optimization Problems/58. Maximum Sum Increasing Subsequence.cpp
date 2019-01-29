#include <iostream>
using namespace std;

// T(n): O(n^2); S(n): O(n);
void Print(int a[], int n, int i){
	cout<<i<<": ";
	for(int i=0; i<n; i++)
		cout<<a[i]<<" ";
	cout<<endl;
}

int main(int argc, char const *argv[])
{
	int n;
	cin>>n;
	int a[n], b[n];
	for(int i=0; i<n; i++){
		cin>>a[i];
		b[i]=0;
	}
	for(int i=n-1; i>-1; i--){
		int max_sum=a[i];
		for(int j=n-1; j>i; j--){
			if(a[j]>a[i]){
				int curr_sum=a[i]+b[j];
				if(max_sum<curr_sum)
					max_sum=curr_sum;
			}
		}
		b[i]=max_sum;
		Print(b, n, i);
	}
	return 0;
}