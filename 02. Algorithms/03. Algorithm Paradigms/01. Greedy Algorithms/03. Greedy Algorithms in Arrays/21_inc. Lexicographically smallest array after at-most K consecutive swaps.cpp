#include<iostream>
#include<vector>

using namespace std;

void Minimize(vector<int> &vec, int n, int k) { //copied
	for (int i = 0; i<n-1 && k>0; ++i) {
		// Set the position where we want to put the smallest integer
		int pos = i;
		for (int j = i+1; j<n ; ++j) {
			// If we exceed the Max swaps then terminate the loop 
			if (j-i > k)
				break;
  		// Find the minimum value from i+1 to // max k or n 
			if (arr[j] < arr[pos])
				pos = j;
		}
		// Swap the elements from Minimum position we found till now to the i index
		for (int j = pos; j>i; --j)
			swap(arr[j], arr[j-1]);
		// Set the final value after swapping pos-i elements 
		k -=  pos-i;
	} 
} 

int main(int argc, char const *argv[]) {
	int n, k;
	cin>>n>>k;
	vector<int> vec(n);
	Minimize(vec, n, k);
	Print(vec);
	return 0;
}