#include <iostream>
#include <unordered_map>
#include <iterator>
using namespace std;

int main(int argc, char const *argv[])
{
	int n;
	cin>>n;
	int a[n];
	for(int i=0; i<n; i++)
		cin>>a[i];
	unordered_map<int, int> map1;
	for(int i=0; i<n; i++)
		map1[a[i]]++;
	unordered_map<int, int>::iterator itr;
	// for(itr=map1.begin(); itr!=map1.end(); itr++)
	// 	cout<<(*itr).first<<" "<<(*itr).second<<endl;
	int m=(n%2)?(n/2+1):(n/2);
	for(itr=map1.begin(); itr!=map1.end(); itr++){
		if((*itr).second>=m){
			cout<<(*itr).first<<endl;
			break;
		}
	}
	return 0;
}