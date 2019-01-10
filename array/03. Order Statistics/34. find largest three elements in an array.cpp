#include <iostream>
using namespace std;

//Linearly check for 3 largest number
//we can also sort the array and then get top 3 elements. but that will take O(n log n) time
//T(n): O(n); S(n): O(1);
int main(int argc, char const *argv[])
{
	int n, a[100];
	cin>>n;
	for(int i=0; i<n; i++)
		cin>>a[i];
	int max1=0, max2=0, max3=0;
	for(int i=0; i<n; i++){
		if(a[i]>max1){
			max3=max2;
			max2=max1;
			max1=a[i];
		}
		else if(a[i]>max2){
			max3=max2;
			max2=a[i];
		}
		else if(a[i]>max3)
			max3=a[i];
	}
	cout<<max1<<" "<<max2<<" "<<max3<<endl;
	return 0;
}