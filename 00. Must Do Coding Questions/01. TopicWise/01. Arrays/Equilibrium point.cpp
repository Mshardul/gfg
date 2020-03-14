#include<iostream>
#include<vector>

using namespace std;

void GetEqu(vector<int> vec, int n){
  if(n==1){
    cout<<n<<endl;
    return;
  }
  
  int l=0, r=n-1;
  int sum_l=vec[l], sum_r=vec[r];
  while(l<r){
    if(sum_l>sum_r){
      sum_r += vec[--r];
    }else if(sum_l<sum_r){
      sum_l += vec[++l];
    }else{
      if((r-l)==2){
        cout<<(l+2)<<endl;
        return;
      }else{
        sum_l += vec[++l];
        sum_r += vec[--r];
      }
    }
  }
  cout<<"-1"<<endl;
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
    
    GetEqu(vec, n);
  }
  return 0;
}