#include<iostream>
#include<vector>
#include<set>
#include<math.h>

using namespace std;

bool isTriplet(vector<int> vec, int n){ //tle
	set<int> st;
	for(int i=0; i<n; i++)
		st.insert(vec[i]);
	for(int i=0; i<n; i++){
		for(int j=i+1; j<n; j++){
			int mult = ((vec[i]*vec[i]) + (vec[j]*vec[j]));
			int toFind = sqrt(mult);
			if(((toFind*toFind)==mult) && (st.find(toFind)!=st.end())){
				cout<<vec[i]<<" "<<vec[j]<<" "<<toFind<<endl;
				return true;
			}
		}
	}
	return false;
}

int main(int argc, char const *argv[]) {
	int t;
	cin>>t;
	while(t-->0){
		int n;
		cin>>n;
		vector<int> vec(n);
		for(int i=0; i<n; i++)
			cin>>vec[i];
		if(isTriplet(vec, n))
			cout<<"Yes\n";
		else
			cout<<"No\n";
	}
	return 0;
}