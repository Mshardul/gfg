#include <iostream>
#include <stack>
using namespace std;

//copied
int main(int argc, char const *argv[])
{
	int n;
	cin>>n;
	
	int ans = 0;

	stack<int> st;
	for(int i=1; i<n && i<=9; i++){
		if(i<=n){
			st.push(i);
			ans++;
		}
		while(!st.empty()){
			int tp = st.top();
			st.pop();
			for(int j=tp%10; j<=9; j++){
				int k = tp*10+j;
				if(k<=n){
					cout<<k<<" ";
					st.push(k);
					ans++;
				}
			}
		}
	}
	cout<<endl<<ans<<endl;
	return 0;
}