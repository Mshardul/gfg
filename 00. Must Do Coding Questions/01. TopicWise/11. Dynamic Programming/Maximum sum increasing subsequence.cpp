#include<iostream>
#include<vector>
#include<limits.h> //for INT_MIN //generally, not required

using namespace std;

void Print(vector<int> vec){
	vector<int>::iterator iter = vec.begin();
	while(iter!=vec.end()){
		cout<<(*iter)<<" ";
		iter++;
	}
	cout<<endl;
}

int sis(vector<int> vec, int n){
	int ans = INT_MIN;
	
	vector<int> dp(n);
	for(int i=0; i<n; i++)
		dp[i] = vec[i];
	
	for(int i=0; i<n; i++){
		int add = 0;
		for(int j=0; j<i; j++){
			if(vec[j]<vec[i] && dp[j]>add){
				add = dp[j];
			}
		}
		if(add>0)
			dp[i] += add;
		if(dp[i]>ans)
			ans = dp[i];
		// Print(dp);
	}
	return ans;
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
		
		cout<<sis(vec, n)<<endl;
	}
	return 0;
}

/* wrong answer for
94
726 32 493 143 223 287 65 901 188 361 414 975 271 171 236 834 712 761 897 668 286 551 141 695 696 625 20 126 577 695 659 303 372 467 679 594 852 485 19 465 120 153 801 88 61 927 11 758 171 316 577 228 44 759 165 110 883 87 566 488 578 475 626 628 630 929 424 521 903 963 124 597 738 262 196 526 265 261 203 117 31 327 12 772 412 548 154 521 791 925 189 764 941 852
*/