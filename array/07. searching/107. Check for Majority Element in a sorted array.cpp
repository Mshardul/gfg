#include <iostream>
using namespace std;

/*
//T(n): O(n);
int main(int argc, char const *argv[])
{
	int n, x;
	cin>>n;
	int a[n];
	for(int i=0; i<n; i++)
		cin>>a[i];
	cin>>x;
	int ans=0;
	for(int i=0; i<n; i++){
		if(a[i]==x)
			ans++;
	}
	int done=0;
	if(n%2==0){
		if(ans==n/2)
			done=1;
	}
	else{
		if(ans==(n/2)+1)
			done=1;
	}
	if(done)
		cout<<"True"<<endl;
	else
		cout<<"False"<<endl;
	return 0;
}
*/

/*
//T(n): O(log n)
int SearchLeftInd(int a[], int l, int r, int x){
	if(l>r)
		return -1;
	int mid=(l+r)/2;
	if(a[mid]<x)
		return SearchLeftInd(a, mid+1, r, x);
	if((a[mid]==x) && ((mid==l) || (mid>l && a[mid-1]<x)))
		return mid;
	return SearchLeftInd(a, l, mid-1, x);
}

int SearchRightInd(int a[], int l, int r, int x){
	if(l>r)
		return -1;
	int mid=(l+r)/2;
	if(a[mid]>x)
		return SearchRightInd(a, l, mid-1, x);
	if((a[mid]==x) && ((mid==r) || (mid<r && a[mid+1]>x)))
		return mid;
	return SearchRightInd(a, mid+1, r, x);
}

int main(int argc, char const *argv[])
{
	int n, x;
	cin>>n;
	int a[n];
	for(int i=0; i<n; i++)
		cin>>a[i];
	cin>>x;
	int li=SearchLeftInd(a, 0, n, x);
	int ri=SearchRightInd(a, 0, n, x);
	int noofele=ri-li+1;
	int done=0;
	if(n%2==0)
		done=(noofele>=n/2)?1:0;
	else
		done=(noofele>n/2)?1:0;
	done?cout<<"True":cout<<"False";
	cout<<endl;
	return 0;
}
*/

//T(n): O(log n)
int SearchLeftInd(int a[], int l, int r, int x){
	if(l>r)
		return -1;
	int mid=(l+r)/2;
	if(a[mid]<x)
		return SearchLeftInd(a, mid+1, r, x);
	if((a[mid]==x) && ((mid==l) || (mid>l && a[mid-1]<x)))
		return mid;
	return SearchLeftInd(a, l, mid-1, x);
}

int main(int argc, char const *argv[])
{
	int n, x;
	cin>>n;
	int a[n];
	for(int i=0; i<n; i++)
		cin>>a[i];
	cin>>x;
	int li=SearchLeftInd(a, 0, n, x);
	int ri=li+n/2;
	int done=0;
	ri-=(n%2==0)?1:0;
	if(ri<n && a[ri]==x)
		done=1;
	done?cout<<"True":cout<<"False";
	cout<<endl;
	return 0;
}