#include<iostream>

using namespace std;

int fibo(int n){
	if(n<2)
		return n;
	int f=0, s=1, t;
	for(int i=2; i<n; i++){
		s = f+s;
		f = s-f;
		cout<<s<<" ";
	}
	return s;
}

int main(int argc, char const *argv[]) {
	int n;
	cin>>n;

	cout<<fibo(n)<<endl;
	return 0;
}