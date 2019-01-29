#include <iostream>
#include <queue>
using namespace std;

int main(int argc, char const *argv[])
{
	int n, temp;
	priority_queue<int, vector<int>, greater<int> > pq;
	while(1){
		cin>>temp;
		pq.push(temp);
		n++;
		cout<<pq[n/2];
	}
	return 0;
}