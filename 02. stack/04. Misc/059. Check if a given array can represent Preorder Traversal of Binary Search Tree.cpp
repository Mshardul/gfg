#include <iostream>
#include <stack>
using namespace std;

/*
//T(n): O(n^2); S(n): O(n);
bool CheckPre(int a[], int l, int r){
	cout<<l<<" "<<r<<endl;
	if(l>=r)
		return true;
	bool right=false;
	int mid;
	for(int i=l+1; i<=r; i++){
		if(a[i]>a[l]){
			if(right==false){
				mid=i;
				right=true;
			}
			if(right!=true)
				right=true;
		}
		else if(a[i]<a[l]){
			if(right==true)
				return false;
		}
	}
	return (CheckPre(a, l+1, mid-1) && CheckPre(a, mid+1, r));
}

int main(int argc, char const *argv[])
{
	int n;
	cin>>n;

	int a[n];
	for(int i=0; i<n; i++)
		cin>>a[i];

	bool res = CheckPre(a, 0, n-1);
	cout<<res<<endl;

	return 0;
}
*/

//Method-2: using stack //copied
bool canRepresentBST(int pre[], int n) 
{ 
    // Create an empty stack
    stack<int> s; 
  
    // Initialize current root as minimum possible value 
    int root = INT_MIN; 
  
    // Traverse given array 
    for (int i=0; i<n; i++) 
    { 
        // If we find a node who is on right side and smaller than root, return false 
        if (pre[i] < root) 
            return false; 
  
        // If pre[i] is in right subtree of stack top, Keep removing items smaller than pre[i] and make the last removed item as new root. 
        while (!s.empty() && s.top()<pre[i]) 
        { 
            root = s.top(); 
            s.pop(); 
        } 
  
        // At this point either stack is empty or pre[i] is smaller than root, push pre[i] 
        s.push(pre[i]); 
    } 
    return true; 
} 