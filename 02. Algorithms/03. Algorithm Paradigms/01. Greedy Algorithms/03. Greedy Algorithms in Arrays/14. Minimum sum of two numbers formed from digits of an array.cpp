#include<iostream>
#include<vector>

using namespace std;

int minSum(vector<int> vec, int n){
	sort(vec.begin(), vec.end());
	int n1=0, n2=0;
	int i = 0;
	while(vec[i]==0) //sorting algo assumes 0>9
		i++;
	for(; i<n; i+=2){
		n1 = (n1*10)+vec[i];
		if(i<n)
			n2 = (n2*10)+vec[i+1];
	}
	cout<<n1<<" "<<n2<<endl;
	return n1+n2;
}

int main(int argc, char const *argv[]) {
	int n;
	cin>>n;
	vector<int> vec(n);
	for(int i=0; i<n; i++)
		cin>>vec[i];
	cout<<minSum(vec, n)<<endl;
	return 0;
}