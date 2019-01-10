#include <iostream>
using namespace std;

/*
// T(n):O(n); S(n):O(1);
int main(int argc, char const *argv[])
{
	int n;
	cin>>n;
	int a[n];
	for(int i=0; i<n; i++)
		cin>>a[i];
	int min, max;
	if(a[0]>a[1]){
		min=a[1];
		max=a[0];
	}
	else{
		min=a[0];
		max=a[1];
	}
	for(int i=2; i<n; i++){
		if(a[i]>max)
			max=a[i];
		else if(a[i]<min)
			min=a[i];
	}
	cout<<min<<" "<<max<<endl;
	return 0;
}
*/

//tournament method //copied
//T(n): O(n); S(n): O(1);
struct pair 
{ 
	int min; 
	int max; 
};

struct pair getMinMax(int arr[], int low, int high) { 
	struct pair minmax, mml, mmr;	 
	int mid;
	if (low == high) 
	{ 
		minmax.max = arr[low]; 
		minmax.min = arr[low];	 
		return minmax; 
	}
	if (high == low + 1) 
	{ 
		if (arr[low] > arr[high]) 
		{ 
			minmax.max = arr[low]; 
			minmax.min = arr[high]; 
		} 
		else
		{ 
			minmax.max = arr[high]; 
			minmax.min = arr[low]; 
		} 
		return minmax; 
	} 
	mid = (low + high)/2; 
	mml = getMinMax(arr, low, mid); 
	mmr = getMinMax(arr, mid+1, high);
	if (mml.min < mmr.min) 
		minmax.min = mml.min; 
	else
		minmax.min = mmr.min;
	if (mml.max > mmr.max) 
		minmax.max = mml.max; 
	else
		minmax.max = mmr.max;	 

	return minmax; 
} 

int main(int argc, char const *argv[])
{
	int n;
	cin>>n;
	int a[n];
	for(int i=0; i<n; i++)
		cin>>a[i];
	struct pair minmax = getMinMax(arr, 0, arr_size-1); 
	printf("nMinimum element is %d", minmax.min); 
	printf("nMaximum element is %d", minmax.max); 
	return 0;
}