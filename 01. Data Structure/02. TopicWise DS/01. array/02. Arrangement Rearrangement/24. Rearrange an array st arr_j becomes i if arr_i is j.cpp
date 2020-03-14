#include <iostream>
using namespace std;

/*
// T(n): O(n); S(n): O(n);
int main(int argc, char const *argv[])
{
	int n, a[100], b[100];
	cin>>n;
	for(int i=0; i<n; i++)
		cin>>a[i];
	for(int i=0; i<n; i++)
		b[a[i]]=i;
	for(int i=0; i<n; i++)
		cout<<b[i]<<" ";
	cout<<endl;
	return 0;
}
*/

//T(n): O(n); S(n): O(1) //copied
//as soon as we process an element we keep its negated value instead of the original value (so that we know, its already processed);
//as we can have '0' as well, we will use -(i+1) instead of just -i;
void rearrangeUtil(int arr[], int n, int i) 
{ 
	int val = -(i+1);
	i = arr[i] - 1;
	while (arr[i] > 0) 
	{ 
		int new_i = arr[i] - 1; 
		arr[i] = val; 
		val = -(i + 1); 
		i = new_i; 
	}
} 

void rearrange(int arr[], int n) 
{
	int i; 
	for (i=0; i<n; i++) 
		arr[i]++;
	for (i=0; i<n; i++) {
		if (arr[i] > 0) 
			rearrangeUtil(arr, n, i); 
	}
	for (i=0; i<n; i++) 
		arr[i] = (-arr[i]) - 1; 
}
  
void printArray(int arr[], int n) 
{ 
    int i; 
    for (i=0; i<n; i++) 
        printf("%d ", arr[i]); 
    printf("\n"); 
} 

int main() 
{ 
    int n, arr[100];
    cin<<n;
    for(int i=0; i<n; i++)
		cin>>arr[i];
	rearrange(arr,  n); 
	printArray(arr, n); 
	return 0; 
} 