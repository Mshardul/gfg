#include<iostream>
#include<vector>

using namespace std;

void Print(vector<int> vec){
	vector<int>::iterator iter = vec.begin();
	while(iter!=vec.end()){
		cout<<*iter<<" ";
		iter++;
	}
	cout<<endl;
}

void KSwapMaximum(int arr[], int n, int k) {
	for (int i = 0; i < n - 1 && k > 0; ++i) { 
  // Here, indexPositionition is set where we want to put the current largest integer 
	int indexPosition = i;
	for (int j = i + 1; j < n; ++j) {
  	// If we exceed the Max swaps then break the loop 
		if (k <= j - i)
			break;
  	// Find the maximum value from i+1 to max k or n which will replace arr[indexPosition] 
		if (arr[j] > arr[indexPosition])
			indexPosition = j;
	}
  // Swap the elements from Maximum indexPosition we found till now to the ith index
	for (int j = indexPosition; j > i; --j)
		swap(arr[j], arr[j - 1]);
  // Updates k after swapping indexPosition-i elements
	k -= indexPosition - i;
	}
} 

/*
void largestArr(vector<int> &vec, int n, int k){ //not for consecutive
	for(int len=0; len<k; len++){
		int maxInd = len;
		for(int i=len+1; i<n; i++){
			if(vec[i]>vec[maxInd])
				maxInd = i;
		}
		swap(vec[maxInd], vec[len]);
	}
}
*/

int main(int argc, char const *argv[]) {
	int n, k;
	cin>>n>>k;
	vector<int> vec(n);
	for(int i=0; i<n; i++)
		cin>>vec[i];
	largestArr(vec, n, k);
	Print(vec);
	return 0;
}