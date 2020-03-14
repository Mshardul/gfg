#include<iostream>
#include<vector>
#include<queue>

using namespace std;

void Print(deque<int> q){
	deque<int>::iterator iter = q.begin();
	while(iter!=q.end()){
		cout<<*iter<<" ";
		iter++;
	}
	cout<<endl;
}

deque<int> Pendulum(vector<int> vec, int n){
	sort(vec.begin(), vec.end());
	deque<int> q;
	for(int i=0; i<n; i++){
		if(i%2==0)
			q.push_front(vec[i]);
		else
			q.push_back(vec[i]);
	}
	return q;
}

int main(int argc, char const *argv[]) {
	int t;
	cin>>t;
	while(t-->0){
		int n;
		cin>>n;
		vector<int> vec(n);
		for(int i=0; i<n; i++)
			cin>>vec[i];
		deque<int> q = Pendulum(vec, n);
		Print(q);
	}
	return 0;
}