#include<iostream>
#include<vector>
#include<queue>

using namespace std;

int arrSum(vector<int> vec, int k){ //tle
	int n = vec.size();
	priority_queue<int, vector<int>, greater<int> > q;
	for(int i=0; i<n; i++)
		q.push(vec[i]);
	for(int i=0; i<k; i++){
		int mn = q.top();
		q.pop();
		q.push(mn*-1);
	}
	long long sum = 0;
	while(!q.empty()){
		sum += q.top();
		q.pop();
	}
	return sum;
}

int arrSum(vector<int> vec, int k){ //tle
	int n = vec.size();
	for(int j=0; j<k; j++){
		int minInd = 0;
		for(int i=1; i<n; i++){
			if(vec[i]<vec[minInd])
				minInd = i;
		}
		if(vec[minInd]==0)
			continue;
		vec[minInd] *= -1;
	}
	long long sum = 0;
	for(int i=0; i<n; i++)
		sum += vec[i];
	return sum;
}

int sum(vector<int> vec, int n){
	vector<int>::iterator iter = vec.begin();
	int ans = 0;
	while(iter!=vec.end()){
		ans += *iter;
		iter++;
	}
	return ans;
}

int arrSum(vector<int> vec, int k){ //tle
	int n = vec.size();
	int neg = 0;
	for(int i=0; i<n; i++){
		if(vec[i]<0)
			neg++;
	}
	for(int j=0; j<min(k, neg); j++){
		int minInd = 0;
		for(int i=0; i<n; i++){
			if(vec[i]<vec[minInd])
				minInd = i;
		}
		vec[minInd] *= -1;
	}
	
	int sum = 0;
	for(int i=0; i<n; i++)
		sum += vec[i];
	
	if(k<neg || (((neg-k)%2)==0))
		return sum;
	
	int minVal = vec[0];
	for(int i=1; i<n; i++)
		if(vec[i]<minVal)
			minVal = vec[i];
	return sum-(2*minVal);
}

int main(int argc, char const *argv[]) {
	int t;
	cin>>t;
	while(t-->0){
		int n, k;
		cin>>n>>k;
		vector<int> vec(n);
		for(int i=0; i<n; i++)
			cin>>vec[i];
		cout<<arrSum(vec, k)<<endl;
	}
	return 0;
}