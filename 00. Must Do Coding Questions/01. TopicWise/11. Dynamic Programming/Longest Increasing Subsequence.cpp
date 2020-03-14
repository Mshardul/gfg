#include<iostream>
#include<vector>

using namespace std;

void Print(vector<int> ans){
	vector<int>::iterator iter;
	for(iter = ans.begin(); iter!=ans.end(); iter++)
		cout<<(*iter)<<" ";
	cout<<endl;
}

vector<int> GetPse(vector<int> vec, int n){ //wrong solution
	vector<int> q;
	q.push_back(0);
	vector<int> ans(n, -1);
	ans[0] = -1;
	for(int i=1; i<n; i++){
		while(!q.empty() && vec[q.back()]>vec[i])
			q.pop_back();
		if(!q.empty())
			ans[i] = q.back();
		q.push_back(i);
	}
	return ans;
}

/*
int _lis( int arr[], int n, int *max_ref) {
	if (n == 1) 
		return 1;
	int res, max_ending_here = 1;
	for (int i = 1; i < n; i++) {
		res = _lis(arr, i, max_ref); 
		if (arr[i-1] < arr[n-1] && res + 1 > max_ending_here)
			max_ending_here = res + 1; 
	}
	if (*max_ref < max_ending_here)
		*max_ref = max_ending_here;
	return max_ending_here;
}

int lis(int arr[], int n) { //copied - top down approach
	int max = 1;
	_lis( arr, n, &max );
	return max;
} 
*/

int lis(vector<int> vec){
	int n = vec.size();
	int l=0, r=0, max = 1;
	vector<int> ansVec(n, 1);
	// bottom up approach
	for(int i=1; i<n; i++){
		for(int j=i-1; j>-1; j--){
			if(vec[i]>vec[j] && ansVec[i]<=ansVec[j]){
					ansVec[i] = 1+ansVec[j];
					if(ansVec[i]>max)
						max = ansVec[i];
			}		
		}
		// Print(ansVec);
	}
	return max;
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
		
		cout<<lis(vec)<<endl;
	}
	return 0;
}