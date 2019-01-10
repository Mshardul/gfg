#include<iostream>
using namespace std;
#include <vector>

//T(n) = O(n); S(n) = O(1)
int main(int argc, char const *argv[])
{
	int t;
	cin>>t;
	while(t-->0){
		int n, input;
		cin>>n;
		vector<int> v;
		for(int i=0; i<n; i++){
			cin>>input; //direclty storing in v[i] giving segmentation fault
			v.push_back(input); //"v[i] = input" giving segmentation fault
		}
		int temp = v[n-1];
		for(int i=n-1; i>0; i--)
			v[i] = v[i-1];
		v[0]=temp;
		for(int i=0; i<n; i++)
			cout<<v[i]<<" ";
		cout<<endl;
	}
	return 0;
}