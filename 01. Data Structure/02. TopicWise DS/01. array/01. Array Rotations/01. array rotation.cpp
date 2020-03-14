#include<iostream>
using namespace std;


//method-1: T(n) = O(n); S(n) = O(n)
int main(int argc, char const *argv[])
{
	int t;
	cin>>t;
	while(t-->0){
		int n, a[1000], d, b[1000];
		cin>>n;
		for(int i=0; i<n; i++)
			cin>>a[i];
		cin>>d;
		for(int i=0; i<n; i++)
			b[i] = a[(i+d)%n];
		for(int i=0; i<n; i++)
			cout<<b[i]<<" ";
		return 0;
	}
}

/*
//method-2: T(n) = O(dn); S(n) = O(1)
int main(int argc, char const *argv[])
{
	int n, a[1000], d;
	cin>>n;
	for(int i=0; i<n; i++)
		cin>>a[i];
	cin>>d;
	while(d-->0){
		int i=0;
		int temp = a[0];
		for(i=0; i<n-1; i++){
			a[i] = a[(i+1)%n];
		}
		a[i]=temp;
	}
	for(int i=0; i<n; i++)
		cout<<a[i];
	return 0;
}
*/
/*
//method-3: T(n) = O(n); S(n) = O(1)
int gcd(int a, int b){
	if(b==0)
		return a;
	return gcd(b, a%b);
}
int main(int argc, char const *argv[])
{
	int n, a[1000], d;
	cin>>n;
	for(int i=0; i<n; i++)
		cin>>a[i];
	cin>>d;
	for (int i = 0; i < gcd(d, n); i++) {
		int temp = a[i];
		int j = i;
		while (1) {
			int k = (j+d)%n;
			if (k == i)
				break;
			a[j] = a[k];
			j = k;
		}
		a[j] = temp;
	}
	for(int i=0; i<n; i++)
		cout<<a[i];
	return 0;
}
*/
/*
//method-4: T(n) = O(n); S(n) = O(1)
void ReverseArr(int a[], int l, int r){
	int n = r-l;
	int temp;
	for(int i=0; i<n/2; i++){
		temp = a[i];
		a[i] = a[n-i-1];
		a[n-i-1] = temp;
	}
}
int main(int argc, char const *argv[])
{
	int n, a[1000], d;
	cin>>n;
	for(int i=0; i<n; i++)
		cin>>a[i];
	cin>>d;
	ReverseArr(a, 0, d-1);
	ReverseArr(a, d, n);
	ReverseArr(a, 0, n);
	for(int i=0; i<n; i++)
		cout<<a[i]<<" ";
	return 0;
}
*/
/* might not be correct
//method-5: T(n) = O(n); S(n)=O(1)
void SwapArr(int a[], int l1, int l2, int n){
	int temp;
	for(int i=0; i<n_a; i++){
		temp = a[l1+i];
		a[l1+i] = a[l2+i];
		a[l2+i] = temp;
	}
}
void Swap(int a[], int l_a, int r_a, int l_b, int r_b){
	int n_a = r_a-l_a;
	int n_b = r_b-l_b;
	if(n_a == n_b){
		SwapArr(a, l_a, l_b, n_a);
	}
	else if(n_a<n_b){
		SwapArr(a, l_a, r_b-n_a, n_a);
		Swap(a, 0, d, d+1, n-d-1);
	}
	else{
		SwapArr(a, l_a, l_b, n_b);
		Swap(a, n-d, d, d+1, n);
	}
}
*/