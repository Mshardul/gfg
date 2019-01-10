#include <iostream> 
#include <string>
#include <vector>
using namespace std; 

//T(n): O(n logn); S(n): O(1); //copied
int myCompare(string X, string Y) 
{
	string XY = X.append(Y);
	string YX = Y.append(X);
	return XY.compare(YX) > 0 ? 1: 0;
}

void printLargest(vector<string> arr) 
{
	sort(arr.begin(), arr.end(), myCompare); 

	for (int i=0; i < arr.size() ; i++ ) 
		cout << arr[i]; 
} 
  
int main() 
{
	int n;
	string temp;
	vector<string> a;
	cin>>n;
	for(int i=0; i<n; i++){
		cin>>temp;
		a.push_back(temp);
	}
	printLargest(a);
}