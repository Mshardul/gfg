#include <iostream>
using namespace std;

/*
//using indexing - only if a[i]<n ∀ i
//T(n): O(n); S(n): O(1);
int main(int argc, char const *argv[])
{
	int n;
	cin>>n;
	int a[n];
	for(int i=0; i<n; i++)
		cin>>a[i];
	for(int i=0; i<n; i++){
		int ind=(a[i]>-1)?1:-1;
		ind*=a[i];
		a[ind]*=-1;
	}
	for(int i=0; i<n; i++){
		if(a[i]<0){
			cout<<i<<endl;
			break;
		}
	}
	return 0;
}
*/

/*
// T(n): O(max{a[i]}); S(n): O(max{a[i]});
void Print(int a[], int n){
	for(int i=0; i<=n; i++)
		cout<<a[i]<<" ";
	cout<<endl;
}

int main(int argc, char const *argv[])
{
	int n;
	cin>>n;
	int a[n];
	for(int i=0; i<n; i++)
		cin>>a[i];
	int max=a[0];
	for(int i=1; i<n; i++){
		if(max<a[i]){
			max=a[i];
		}
	}
	int b[max+1];
	for(int i=0; i<=max; i++)
		b[i]=0;
	Print(b, max);
	for(int i=0; i<n; i++){
		b[a[i]]++;
		cout<<i<<" ";
		Print(b, max);
	}
	for(int i=0; i<=max; i++){
		if(b[i]==1){
			cout<<i<<endl;
			break;
		}
	}
	return 0;
}
*/

//using xor property: [a^a=0]; a^0=a]
//T(n): O(n); S(n): O(1);
int main(int argc, char const *argv[])
{
	int n;
	cin>>n;
	int a[n];
	for(int i=0; i<n; i++)
		cin>>a[i];
	int xor_val=0;
	for(int i=0; i<n; i++)
		xor_val=xor_val^a[i];
	cout<<xor_val<<endl;
	return 0;
}