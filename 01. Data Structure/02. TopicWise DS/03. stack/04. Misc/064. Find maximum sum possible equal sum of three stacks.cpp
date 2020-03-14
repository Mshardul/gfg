#include <iostream>
#include <stack>
using namespace std;

int main(int argc, char const *argv[])
{
	int n1, n2, n3;
	cin>>n1>>n2>>n3;

	int s1, s2, s3;
	cin>>s1>>s2>>s3;

	int temp;
	stack<int> st1, st2, st3;
	for(int i=0; i<n1; i++){
		cin>>temp;
		st1.push(temp);
	}
	for(int i=0; i<n2; i++){
		cin>>temp;
		st2.push(temp);
	}
	for(int i=0; i<n3; i++){
		cin>>temp;
		st3.push(temp);
	}

	bool ans=false;
	while(!st1.empty() || !st2.empty() || !st3.empty()){
		if(s1==s2 && s2==s3){
			ans=true;
			break;
		}
		if(s1>s2){
			if(s1>s3){ //s1 is max
				cout<<"popped from 1\n";
				s1-=st1.top();
				st1.pop();
			}
			else if(s3>s1){ //s3>s1>s2
				cout<<"popped from 3\n";
				s3-=st3.top();
				st3.pop();
			}
			else{ //s1 and s3 are max
				cout<<"popped from 1 & 3\n";
				s1-=st1.top();
				st1.pop();
				s3-=st3.top();
				st3.pop();
			}
		}
		else if(s2>s1){ //s2>s1
			if(s3>s2){ //s3>s2>s1
				cout<<"popped from 3\n";
				s3-=st3.top();
				st3.pop();
			}
			else if(s2>s3){ //s2 is max
				cout<<"popped from 2\n";
				s2-=st2.top();
				st2.pop();
			}
			else{ //both s2 and s3 are max;
				cout<<"popped from 2 & 3\n";
				s3-=st3.top();
				st3.pop();
				s2-=st2.top();
				st2.pop();
			}
		}
		else{ //s1==s2
			if(s1>s3){ //s1 and s2 are max
				cout<<"popped from 1 & 2\n";
				s1-=st1.top();
				st1.pop();
				s2-=st2.top();
				st2.pop();
			}
			else{ //s3 is max
				cout<<"popped from 3\n";
				s3-=st3.top();
				st3.pop();
			}
		}
	}

	if(ans)
		cout<<s1<<endl;
	else
		cout<<"Not possible!!\n";
	return 0;
}