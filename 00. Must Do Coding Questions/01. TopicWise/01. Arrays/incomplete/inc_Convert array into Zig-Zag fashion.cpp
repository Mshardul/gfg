#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

void PrintZigZag(vector<int> vec, int n){
  sort(vec.begin(), vec.end());
  int ind=n/2;
  if(n%2==1)
    ind++;
  for(int i=0; i<ind; i++){
    cout<<vec[i]<<" ";
    if(i+ind<n)
      cout<<vec[i+ind]<<" ";
  }
  cout<<endl;
}

void PrintZigZag2(vector<int> vec, int n){ //maintain order
  
}

int main(int argc, char const *argv[]) {
  int t;
  cin>>t;
  
  while(t-->0){
    int n;
    cin>>n;
    
    vector<int> vec(n);
    
    for(int i=0; i<n; i++)
      cin>>vec[i];
      
    PrintZigZag2(vec, n);
  }
  return 0;
}