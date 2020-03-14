#include <iostream>
#include <vector>
#include <stack>
using namespace std;

/*
//using vector
//T(n): O(n^2); S(n): O(n);

void Display(vector<string> v){
	for(vector<string>::iterator iter = v.begin(); iter!=v.end(); iter++)
		cout<<*iter<<" ";
	cout<<endl;
}

int main(int argc, char const *argv[])
{
	int n;
	cin>>n;

	string s;
	vector<string> vec;
	for(int i=0; i<n; i++){
		cin>>s;
		vec.push_back(s);
	}

	Display(vec);
	int i=1;
	while(!vec.empty() && i<vec.size()){
		cout<<i;
		if(vec[i-1]==vec[i]){
			vec.erase(vec.begin()+i-1, vec.begin()+i+1);
			i-=2;
		}
		else
			i++;
		Display(vec);
	}

	cout<<s;
	return 0;
}
*/

//using stack
// T(n): O(n); S(n): O(n);
void Display(stack<string> st){
	while(!st.empty()){
		cout<<st.top()<<" ";
		st.pop();
	}
	cout<<endl;
}

int main(int argc, char const *argv[])
{
	int n;
	cin>>n;

	stack<string> st;
	string str;

	for(int i=0; i<n; i++){
		cin>>str;
		if(!st.empty() && str==st.top())
			st.pop();
		else
			st.push(str);
	}

	Display(st);

	return 0;
}