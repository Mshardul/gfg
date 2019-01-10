#include <iostream>
using namespace std;

//using kadane's algo
// T(n): O(n); S(n): O(1)
int main(int argc, char const *argv[])
{
	int n;
	cin>>n;
	int a[n];
	for(int i=0; i<n; i++)
		cin>>a[i];
	int curr_sum=0, max_sum=INT_MIN, ans=0, temp_ans=0;
	for(int i=0; i<n; i++){
		curr_sum+=a[i];
		temp_ans++;
		if(curr_sum>max_sum){
			max_sum=curr_sum;
			ans=temp_ans;
		}
		if(curr_sum<0){
			curr_sum=0;
			temp_ans=0;
		}
	}
	cout<<ans<<endl;
	return 0;
}