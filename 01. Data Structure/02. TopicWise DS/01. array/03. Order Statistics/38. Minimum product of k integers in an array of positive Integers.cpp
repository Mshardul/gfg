#include <iostream>
#include <queue>
using namespace std;

/*
//sort the array, and get product of k smallest elements
//T(n)=O(n log n); S(n):O(1);
int main(int argc, char const *argv[])
{
	int n, a[100], k;
	cin>>n;
	for(int i=0; i<n; i++)
		cin>>a[i];
	sort(a, a+n);
	cin>>k;
	int ans=1;
	for(int i=0; i<k; i++)
		ans*=a[i];
	cout<<ans;
	return 0;
}
*/
//using priority queue
//T(n): O(n log n); S(n): O(1);
int main(int argc, char const *argv[])
{
	int n, k, temp, ans=1;
	priority_queue<int, vector<int>, greater<int> > pq;
	cin>>n;
	for(int i=0; i<n; i++){
		cin>>temp;
		pq.push(temp);
	}
	cin>>k;
	for(int i=0; i<k; i++){
		ans*=pq.top();
		pq.pop();
	}
	cout<<ans;
	return 0;
}

//using rank(), it can be solved in O(n);
//T(n): O(n); S(n): O(1);