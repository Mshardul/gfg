#include<iostream>
#include<vector>
#include<queue>

using namespace std;

void Print(vector<int> vec){
	vector<int>::iterator iter = vec.begin();
	while(iter!=vec.end()){
		cout<<*iter<<" ";
		iter++;
	}
	cout<<endl;
}

/*
int steps(vector<int> vec, int n){ //only for decrement possibility
	int ans = 0;
	for(int i=1; i<n; i++){
		if(vec[i]<=vec[i-1])
			continue;
		ans += vec[i]-vec[i-1];
		vec[i] = vec[i-1];
	}
	Print(vec);
	return ans;
}
*/

int steps(vector<int> a, int n) { //copied
	int sum = 0, dif = 0;
	priority_queue<int, vector<int>, greater<int> > pq;
	// Here in the loop we will check that whether the upcoming element of array is less than top of priority queue. If yes then we calculate the difference. After that we will remove that element and push the current element in queue. And the sum is incremented by the value of difference 
	for (int i = 0; i < n; i++) {
		if (!pq.empty() && pq.top() < a[i]) {
			dif = a[i] - pq.top();
			sum += dif;
			pq.pop();
			pq.push(a[i]);
		}
		pq.push(a[i]);
		cout<<i<<" "<<dif<<" "<<sum<<endl;
	}
	
  return sum;
}

int main(int argc, char const *argv[]) {
	int n;
	cin>>n;
	vector<int> vec(n);
	for(int i=0; i<n; i++)
		cin>>vec[i];
	cout<<steps(vec, n)<<endl;
	return 0;
}