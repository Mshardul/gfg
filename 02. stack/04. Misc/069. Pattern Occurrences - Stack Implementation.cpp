#include <iostream>
#include <stack>

using namespace std;

void Display(int i, stack<string> st){
	cout<<i<<"**********\n";
	while(!st.empty()){
		cout<<st.top()<<",";
		st.pop();
	}
	cout<<endl;
}

int main(int argc, char const *argv[])
{
	string p, t, temp;
	getline(cin, t);
	getline(cin, p);
	
	int n_t=t.length();
	int n_p=p.length();

	stack<string> st;

	int len=1;
	for(int i=0; i<n_t; i++){
		if(st.empty())
			st.push(string(1, t[i]));
		else{
			len=(st.top()).length();
			if(len==1){
				if((st.top())==(string(1, p[0])) && t[i]==p[1]){
					temp=st.top();
					st.pop();
					temp.push_back(t[i]);
					st.push(temp);
				}
				else{
					temp=string(1, t[i]);
					st.push(temp);
				}
			}
			else{
				if(t[i]==p[len]){
					temp=st.top();
					st.pop();
					temp.push_back(t[i]);
					st.push(temp);
				}
				else{
					temp=string(1, t[i]);
					st.push(temp);
				}
			}
		}
		Display(i, st);
		if(st.top()==p){
			cout<<"found---------->\n";
			st.pop();
		}
	}

	return 0;
}