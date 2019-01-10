#include <iostream>
#include <vector>
using namespace std;

int main(int argc, char const *argv[])
{
	int n, temp, i, ind;
	vector<int> v;
	cin>>n;
	for(i=0; i<n; i++){
		cin>>temp;
		v.push_back(temp);
	}
	sort(v.begin(), v.end());
	for(i=0; i<n; i++)
		cout<<v[i]<<" ";
	cout<<endl;
	vector<int> res;
	int mid=(n-1)/2;
	res.push_back(v.at(mid));
	for(int i=1; i<=mid; i++){
		res.push_back(v.at(mid+i));
		res.push_back(v.at(mid-i));
	}
	if(n%2==0)
		res.push_back(v.at(n-1));
	for(int i=0; i<n; i++)
		cout<<res[i]<<" ";
	cout<<endl;
	return 0;
}