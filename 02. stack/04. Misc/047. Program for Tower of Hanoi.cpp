#include <iostream>
#include <stack>
using namespace std;

//T(n): O(2^n); S(n): O(1);
void TOH(char a, char b, char c, int n){
	if(n==1){
		cout<<"pushing "<<n<<" from "<<a<<" to "<<c<<endl;
		return;
	}
	TOH(a, c, b, n-1);
	cout<<"pushing "<<n<<" from "<<a<<" to "<<c<<endl;
	TOH(b, a, c, n-1);
}
int main(int argc, char const *argv[])
{
	int n;
	cin>>n;

	char a='A';
	char b='B';
	char c='C';

	TOH(a, b, c, n);
	return 0;
}