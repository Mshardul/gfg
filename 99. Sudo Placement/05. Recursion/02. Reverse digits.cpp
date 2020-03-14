#include<iostream>

using namespace std;

void Reverse(long long n, bool isFirst){
	if(n==0)
		return;
	int rem = n%10;
	if(rem!=0 || !isFirst){
		isFirst = false;
		cout<<rem;
	}
	Reverse(n/10, isFirst);
}

int main(int argc, char const *argv[]) {
	int t;
	cin>>t;
	while(t-->0){
		long long n;
		cin>>n;
		Reverse(n, true);
		cout<<endl;
	}
	return 0;
}