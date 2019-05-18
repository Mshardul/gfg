#include<iostream>
#include<vector>

using namespace std;

void ReverseInGroups(vector<int> *vec, int n, int k){
  int temp;
  int grp = n/k;
  for(int i=0; i<grp; i++){
    int l = (i*k);
    int r = ((i+1)*k)-1;
    while(l<r){
      temp = (*vec)[l];
      (*vec)[l++] = (*vec)[r];
      (*vec)[r--] = temp;
    }
  }
  
  if(grp*k!=n){
    int l = (grp*k);
    int r = n-1;
    while(l<r){
      temp = (*vec)[l];
      (*vec)[l++] = (*vec)[r];
      (*vec)[r--] = temp;
    }
  }
  
  for(int i=0; i<n; i++)
    cout<<(*vec)[i]<<" ";
  cout<<endl;
}

int main(int argc, char const *argv[]) {
  int t;
  cin>>t;
  
  while(t-->0){
    int n, k;
    cin>>n>>k;
    
    vector<int> vec(n);
    for(int i=0; i<n; i++)
      cin>>vec[i];
      
    ReverseInGroups(&vec, n, k);
  }
  return 0;
}