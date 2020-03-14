#include<iostream>
#include<vector>
using namespace std;

int maxLen(int arr[], int n) { //copied - using hashing, linear time
	unordered_map<int, int> presum;
  int sum = 0;
	int max_len = 0;
	for(int i=0; i<n; i++) {
		sum += arr[i];
		if (arr[i]==0 && max_len==0) 
			max_len = 1;
		if (sum == 0)
			max_len = i+1;
		if(presum.find(sum) != presum.end()) {
			max_len = max(max_len, i-presum[sum]); 
		}else{
			presum[sum] = i;
		}
	}
  return max_len;
} 

/*
int maxLen(int A[],int n){
	vector<int> vec(n+1);
	vec[0] = 0;
	vec[1] = A[0];
  for(int i=1; i<n; i++)
		vec[i+1] = vec[i]+A[i];
	
	int ans = 0;
	for(int i=0; i<=n; i++){
		for(int j=i+1+ans; j<=n; j++){
			int sum = vec[j]-vec[i];
			cout<<i<<" "<<j<<" "<<sum<<endl;
			if(sum==0){
				if((j-i)>ans)
					ans = j-i;
			}
		}
	}
	return ans;
}
*/

int main(int argc, char const *argv[]) {
	int n;
	cin>>n;
	int a[n];
	for(int i=0; i<n; i++)
		cin>>a[i];
	cout<<maxLen(a, n)<<endl;
	return 0;
}