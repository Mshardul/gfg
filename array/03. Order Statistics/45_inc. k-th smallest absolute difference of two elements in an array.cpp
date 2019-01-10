#include <iostream>
#include <queue>
using namespace std;

/*
//this is a brute force approach. can also be solved in O(n log n) using sorting and binary search approah for further computation
//T(n): O(n^2); S(n):O(n^2);
int main(int argc, char const *argv[])
{
	int n, temp, k;
	cin>>n;
	int a[n];
	for(int i=0; i<n; i++)
		cin>>a[i];
	cin>>k;
	priority_queue<int, vector<int>, greater<int> > pq;
	for(int i=0; i<n; i++){
		for(int j=i+1; j<n; j++){
			temp=(a[i]>a[j])?(a[i]-a[j]):(a[j]-a[i]);
			pq.push(temp);
		}
	}
	for(int i=1; i<k; i++){
		pq.pop();
	}
	cout<<pq.top()<<endl;
	return 0;
}
*/

//method-2