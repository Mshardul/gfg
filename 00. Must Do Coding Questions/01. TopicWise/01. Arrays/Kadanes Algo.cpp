#include<iostream>
#include<vector>

using namespace std;

void Kadane(vector<int> vec){
  int n = vec.size();
  int l = 0, r = 0, sum = vec[0], max = vec[0];
  while(r<n){
    if(sum<0){
      l = ++r;
      if(r<n)
        sum = vec[r];
    }else{
      ++r;
      if(r<n)
        sum += vec[r];
    }
    if(sum>max)
      max = sum;
  }
  cout<<max<<endl;
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
    
    Kadane(vec);
  }
  return 0;
}