#include <iostream>
#include <vector>
#include <stack>
using namespace std;

/*
//Method 1: using a stack
//T(n): O(n log n); S(n): O(n)
int compare(pair<int, int> a, pair<int, int> b){
	if(a.first>b.first)
		return 1;
	return -1;
}

int main(int argc, char const *argv[])
{
	int n;
	cin>>n;

	vector<pair<int, int> > v(n);

	for(int i=0; i<n; i++)
		cin>>((v[i]).first)>>((v[i]).second);

	sort(v.begin(), v.end()); //sorts on the basis of first element of pair, in ascending order

	// for(int i=0; i<n; i++)
		// cout<<((v[i]).first)<<" "<<((v[i]).second)<<endl;

	stack<pair<int, int> > st;

	st.push(v[0]);

	for(int i=1; i<n; i++){
		if(((v[i]).first) <= ((st.top()).second))
			(st.top()).second = max(((st.top()).second), ((v[i]).second));
		else
			st.push(v[i]);
	}

	cout<<"Result: \n";
	while(!st.empty()){
		cout<<((st.top()).first)<<" "<<((st.top()).second)<<endl;
		st.pop();
	}

	return 0;
}
*/

//Method 2: using constant space
//T(n): O(n); S(n): O(1);
int main(int argc, char const *argv[])
{
	int n;
	cin>>n;

	vector<pair<int, int> > v(n);

	for(int i=0; i<n; i++)
		cin>>((v[i]).first)>>((v[i]).second);

	sort(v.begin(), v.end()); 

	vector<pair<int, int> >::iterator iter = v.begin();

	while((iter!=v.end()) && n>1){
		if(((*iter).second) >= ((*(iter+1)).first)){
			((*iter).second) = max(((*iter).second), ((*(iter+1)).second));
			v.erase(iter+1);
		}
		else{
			iter++;
		}
		n--;
	}

	for(iter=v.begin(); iter!=v.end(); iter++)
		cout<<((*iter).first)<<" "<<((*iter).second)<<endl;
	
	return 0;
}