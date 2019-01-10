#include <iostream>
using namespace std;

// This is a brute force solution; I think it can get better. cant think of anything as of now.
// T(n): O(n^2); S(n): O(2n);
int main(int argc, char const *argv[])
{
	int n, a[1000], b[2000];
	cin>>n;
	for(int i=0; i<n; i++){
		cin>>a[i];
		b[i]=a[i];
		b[n+i]=a[i];
	}
	int maxDist=0, maxInd=0;
	for(int i=0; i<n; i++){
		int currDist=0;
		for(int j=0; j<n; j++){
			if(a[j]!=b[i+j])
				currDist++;
		}
		if(currDist>maxDist){
			maxDist=currDist;
			maxInd=i;
		}
		cout<<currDist<<" of rotation "<<i<<endl;
	}
	cout<<maxDist<<" of rotation "<<maxInd<<endl;
	return 0;
}