#include <iostream>
using namespace std;

void PrintArr(int a[], int n){
	for(int i=0; i<n; i++)
		cout<<a[i]<<" ";
	cout<<endl;
}

/*
//T(n): O(n); S(n):O(1); //not inorder - can be made inorder using O(n) extra space
int main(int argc, char const *argv[])
{
	int n, a[100];
	cin>>n;
	for(int i=0; i<n; i++)
		cin>>a[i];
	int l=0, r=n-1;
	while(l<=r){
		if(a[l]%2==0)
			l++;
		else if(a[r]%2==1)
			r--;
		else{
			int temp=a[l];
			a[l]=a[r];
			a[r]=temp;
		}
	}
	PrintArr(a, n);
	return 0;
}
*/

//Lomuto's Partition Scheme
//T(n): O(n); S(n): O(1); //not inorder
using namespace std; 
  
// Function to segregate even odd numbers 
void Lomuto(int arr[], int n) 
{ 
	int i = -1, j = 0; 
	int t; 
	while (j != n) { 
		if (arr[j] % 2 == 0) { 
			i++;
			swap(arr[i], arr[j]); 
		}
		j++; 
	}
	for (int i = 0; i < n; i++) 
		cout << arr[i] << " "; 
}

int main() 
{ 
	int n, a[100];
	cin>>n;
	for(int i=0; i<n; i++)
		cin>>a[i];
	Lomuto(a, n); 
	return 0; 
} 