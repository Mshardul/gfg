#include <iostream>
#include <vector>
using namespace std;

int main(int argc, char const *argv[])
{
	int n, k;
	cin>>n>>k;

	vector<int> v(n);
	for(int i=0; i<n; i++){
		cin>>v[i];
	}

	vector<int>::iterator iter = v.begin();
	while(iter!=v.end()){
		if(iter+1==v.end() || k==0)
			break;
		if(*iter<*(iter+1)){
			cout<<*iter<<" ";
			v.erase(iter);
			if(iter>v.begin())
				iter--;
			k--;
		}
		else
			iter++;
	}
	cout<<endl;

	iter=v.begin();
	while(iter!=v.end()){
		cout<<*iter<<" ";
		iter++;
	}
	cout<<endl;
	return 0;
}