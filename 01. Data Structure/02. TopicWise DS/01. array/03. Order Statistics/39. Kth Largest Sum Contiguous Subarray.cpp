#include <iostream>
#include <queue>
using namespace std;

int main(int argc, char const *argv[])
{
	int n, a[100], k, i, sum;
	cin>>n;
	for(i=0; i<n; i++)
		cin>>a[i];
	cin>>k;
	for(i=1; i<n; i++)
		a[i]+=a[i-1];
	priority_queue<int, vector<int>, greater<int> > pq;
	pq.push(a[0]);
	i=0;
	while(i<k && i<n){
		pq.push(a[i]);
		i++;
	}
	while(i<n){
		if(pq.top()<a[i])
			pq.push(a[i]);
	}
	for(i=0; i<n; i++){
		for(int j=i+1; j<n; j++){
			sum=a[j]-a[i];
			if(pq.size()>k){
				if(pq.top()<sum){
					pq.pop();
					pq.push(sum);
				}
			}
			else{
				pq.push(sum);
			}
		}
	}
	// for(int i=0; i<k; i++){
	// 	cout<<pq.top()<<" ";
	// 	pq.pop();
	// }
	cout<<pq.top();
}