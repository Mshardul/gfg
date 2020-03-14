#include<iostream>
using namespace std;

void RecurseTillNegative(int &curr){
	cout<<curr<<" ";
	if(curr<1)
		return;
	curr -= 5;
	RecurseTillNegative(curr);
}

void RecurseTillFinal(int curr, int final){
	cout<<curr<<" ";
	if(curr==final)
		return;
	RecurseTillFinal(curr+5, final);
}
void Pattern(int n){
	cout<<n<<" ";
	int curr = (n>0)?(n-5):(n+5);
	RecurseTillNegative(curr);
	curr += 5;
	RecurseTillFinal(curr, n);
	cout<<endl;
}

int main(int argc, char const *argv[]) {
	int t;
	cin>>t;
	while(t-->0){
		int n;
		cin>>n;
		Pattern(n);
	}
	return 0;
}