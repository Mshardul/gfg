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

bool cmp(pair<int, int> p1, pair<int, int> p2){
	if(p1.first<p2.first)
		return true;
	if(p2.first>p1.first)
		return false;
	if(p1.second<p2.second)
		return true;
	return false;
}

void PrintQ(priority_queue<pair<int, int>, vector<pair<int, int> >, greater<pair<int, int> > > q){
	cout<<"-----------\n";
	while(!q.empty()){
		pair<int, int> p = q.top();
		q.pop();
		cout<<p.first<<" "<<p.second<<endl;
	}
	cout<<"-----------\n";
}

int bookings(vector<int> arr, vector<int> dep, int n, int k){
	priority_queue<pair<int, int>, vector<pair<int, int> >, greater<pair<int, int> > > q;
	for(int i=0; i<n; i++)
		q.push(make_pair(arr[i], dep[i]));
	PrintQ(q);
	vector<int> vec(k, 0);
	while(!q.empty()){
		pair<int, int> p = q.top();
		q.pop();
		int ind = -1;
		for(int i=0; i<k; i++){
			if(vec[i]<=p.first){
				ind = i;
				break;
			}
		}
		if(ind==-1)
			return false;
		else
			vec[ind] = p.second;
		cout<<p.first<<" @ "<<ind<<endl;
		Print(vec);
	}
	return true;
}

bool areBookingsPossible(vector<int> arr, vector<int> dep, int n, int k) { //copied
	int x = 1; //innitial room
	sort(arr.begin(), arr.end());
	sort(dep.begin(), dep.end());
  // check if departure of previous booking overlaps the arrival of next booking or not. 
	for (int i = 0; i < n - 1; i++) {
		if (departure[i] > arrival[i]) 
			x++;
		if (k < x)
			return false;
	}
	return true;
} 

int main(int argc, char const *argv[]) {
	int n, k;
	cin>>n>>k;
	
	vector<int> arr(n);
	for(int i=0; i<n; i++)
		cin>>arr[i];
		
	vector<int> dep(n);
	for(int i=0; i<n; i++)
		cin>>dep[i];
	
	cout<<bookings(arr, dep, n, k)<<endl;
	
	return 0;
}