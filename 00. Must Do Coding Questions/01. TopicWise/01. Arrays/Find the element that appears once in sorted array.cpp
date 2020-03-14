//all elements except one appear twice.

#include<iostream>
#include<vector>

using namespace std;

void GetSingleEle(vector<int> vec, int n){ //works even for unsorted array
  int ans = 0;
  for(int i=0; i<n; i++)
    ans ^= vec[i];
  cout<<ans<<endl;
}

void GetSingleEle2(vector<int> vec, int n){ //only for sorted array
  for(int i=0; i<n; i+=2){
    if(i+1==n || vec[i]!=vec[i+1]){
      cout<<vec[i]<<endl;
      return;
    }  
  }
  cout<<"-1\n";
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
    
    GetSingleEle(vec, n);
  }
  return 0;
}