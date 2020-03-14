#include<iostream>
#include<vector>

using namespace std;

int func(int n, int endsWith0, int endsWith1){
	if(n==1)
		return endsWith0+endsWith1;
	else
		return func(n-1, endsWith0+endsWith1, endsWith0);
}

int main(int argc, char const *argv[]) {
	int n;
	cin>>n;
	
	cout<<func(n, 1, 1)<<endl;
	
	return 0;
}