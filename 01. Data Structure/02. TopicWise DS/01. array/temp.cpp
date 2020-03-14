#include <iostream>
using namespace std;

int main() {
	int t;
	cin>>t;
	long int n, res=0;
	long double curr=0, prev=0;
	while(t-->0){
		cout<<"while";
	    cin>>n;
	    cout<<n;
	    prev=0;
	    res=0;
	    for(long int i=0; i<n; i++){
	        cin>>curr;
	        if(curr<prev){
	            res=i;
	            break;
	        }
	        prev=curr;
	    }
	    cout<<res<<"\n";
	}
	return 0;
}

// 2
// 5
// 2 1 2 2 2
// 3
// 2 1 3