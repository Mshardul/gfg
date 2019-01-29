#include <iostream>
#include <vector>
using namespace std;

//T(n) = O(n); S(n) = O(1);
int GetMaxIndex(vector<int>& v, int l, int r){ //as time complexity goes till O(n) for checking sum, we can linearly check for the index with max element;
	if(l>r)
		return r;
	int mid = (l+r)/2;
	if(v[mid]>v[mid+1])
		return mid;
	if(v[l]<=v[mid])
		return GetMaxIndex(v, mid+1, r);
	return GetMaxIndex(v, l, mid-1);
}
int main(int argc, char const *argv[])
{
	int n, x, input, res=0;
	vector<int> v;
	cin>>n;
	for(int i=0; i<n; i++){
		cin>>input;
		v.push_back(input);
	}
	cin>>x;
	int max = GetMaxIndex(v, 0, n-1);
	int min = (max+1)%n;
	cout<<max<<"\t"<<min;
	while(v[min]<v[max]){
		if(v[max]+v[min]==x){
			res=1;
			break;
		}
		if((v[max]+v[min])<x)
			min = (min+1)%n;
		else{ //r = (n + r - 1)%n;
			if(max==0)
				max=n-1;
			else
				max = max-1;
		}
	}
	if(res==0)
		cout<<"not found";
	else
		cout<<"found";
	return 0;
}