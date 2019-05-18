#include<iostream>

using namespace std;

int GetSum(int n){
  int sum = 0;
  for(int i=1; i<=n; i++)
    sum += i;
  return sum;
}

int main(int argc, char const *argv[]) {
  int t;
  cin>>t;
  
  while(t-->0){
    int n, temp;
    cin>>n;
    
    int sum = GetSum(n);
    for(int i=1; i<n; i++){
      cin>>temp;
      sum -= temp;
    }
    
    cout<<sum<<endl;
  }
  return 0;
}