#include <iostream>
using namespace std;

/*
//T(n): O(n^2); S(n): O(1); //but not inorder
int main(int argc, char const *argv[])
{
	int n, a[1000], i;
	cin>>n;
	for(i=0; i<n; i++)
		cin>>a[i];
	int pos=(a[0]>0)?1:0;
	int ind=1;
	while(ind<n){
		if(pos==1 && a[ind]>0){
			for(i=ind+1; i<n; i++){
				if(a[i]<0){
					int temp=a[ind];
					a[ind]=a[i];
					a[i]=temp;
					pos=0;
					ind++;
					break;
				}
			}
			if(i==n)
				break;
		}
		else if(pos==0 && a[ind]<0){
			for(i=ind+1; i<n; i++){
				if(a[i]>0){
					int temp=a[ind];
					a[ind]=a[i];
					a[i]=temp;
					pos=1;
					ind++;
					break;
				}
			}
			if(i==n)
				break;
		}
		else{
			pos=!pos;
			ind++;
		}
	}
	for(int i=0; i<n; i++)
		cout<<a[i]<<" ";
	cout<<endl;
	return 0;
}
*/

/*
//T(n): O(n); S(n): O(1); //not inorder
void Swap(int *x, int *y){
	int temp=*x;
	*x = *y;
	*y = temp;
}

void Print(int a[], int n){
	for(int i=0; i<n; i++)
		cout<<a[i]<<" ";
	cout<<endl;
}
int main(int argc, char const *argv[])
{
	int n, a[1000];
	cin>>n;
	for(int i=0; i<n; i++)
		cin>>a[i];
	int l=0, r=n-1;
	while(l<r){
		cout<<l<<" "<<r<<endl;
		if(a[l]>0)
			l++;
		else
			Swap(&a[l], &a[r]);
		if(a[r]<0)
			r--;
		else
			Swap(&a[l], &a[r]);
		Print(a, n);
	}
	if(l==r){
		if(a[l]<0)
			l--;
		else
			r++;
	}
	int i=0;
	while(i<=l && r<n){
		cout<<a[i++]<<" "<<a[r++]<<" ";
	}
	while(i<=l)
		cout<<a[i++]<<" ";
	while(r<n)
		cout<<a[r++]<<" ";
	// for(int i=0; i<n; i++)
	// 	cout<<a[i]<<" ";
	return 0;
}
*/

/*
// T(n): O(n); S(n): O(n); //inorder
int main(int argc, char const *argv[])
{
	int n, a[100], b[100], b_ind=0;
	cin>>n;
	int p_ind=0, n_ind=0, curr_ele;
	for(int i=0; i<n; i++)
		cin>>a[i];
	b[b_ind++]=a[0];
	if(b[0]>0){
		p_ind++;
		curr_ele=1;
	}
	else{
		n_ind++;
		curr_ele=-1;
	}
	while(p_ind<n && n_ind<n){
		if(curr_ele==1){
			while(a[n_ind++]>0 && n_ind<n);
			if((n_ind<n)||(n_ind==n && a[n_ind-1]<0)){
				b[b_ind++]=a[n_ind-1];
				curr_ele=-1;
			}
			else{
				while(p_ind<n){
					if(a[p_ind]>0)
						b[b_ind++]=a[p_ind];
					p_ind++;
				}
			}
		}
		else if(curr_ele==-1){
			while(a[p_ind++]<0 && p_ind<n);
			if((p_ind<n)||(p_ind==n && a[p_ind-1]>0)){
				b[b_ind++]=a[p_ind-1];
				curr_ele=1;
			}
			else{
				while(n_ind<n){
					if(a[n_ind]<0)
						b[b_ind++]=a[n_ind];
					n_ind++;
				}
			}
		}
	}
	// cout<<p_ind<<" "<<n_ind<<endl;
	////use these while cases when not using else statements in the while loop above;
	// while(p_ind<n){
	// 	if(a[p_ind]>0)
	// 		b[b_ind++]=a[p_ind];
	// 	p_ind++;
	// }
	// while(n_ind<n){
	// 	if(a[n_ind]<0)
	// 		b[b_ind++]=a[n_ind];
	// 	n_ind++;
	// }
	for(int i=0; i<n; i++)
		cout<<b[i]<<" ";
	cout<<endl;
	return 0;
}
*/

//T(n): O(n); S(n): O(1); inorder //copied
using namespace std; 

bool comp(int a, int b) { 
	// swap not needed 
	if((a > 0 && b > 0) || (a < 0 && b < 0) || (a > 0 && b < 0 )) 
		return false; 
	// swap needed 
	if(a < 0 && b > 0) 
		return true; 
	// swap not needed 
	if((a == 0 && b < 0) || (a > 0 && b == 0)) 
		return false; 
	// swap needed 
	if((a == 0 && b > 0) || (a < 0 && b == 0)) 
		return true; 
}

void rearrange(int arr[], int n) {
	sort(arr, arr + n, comp); 
} 

int main() 
{ 
	int n, arr[100];
	cin>>n;
	for(int i=0; i<n; i++)
		cin>>a[i];
	rearrange(arr, n); 
	for (int i = 0; i < n; i++) 
		cout << " " << arr[i]; 

	return 0; 
} 

