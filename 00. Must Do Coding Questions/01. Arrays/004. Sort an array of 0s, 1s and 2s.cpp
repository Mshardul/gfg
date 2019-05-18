#include<iostream>
#include<vector>

using namespace std;

int main(int argc, char const *argv[]) {
  int t;
  cin>>t;
  
  while(t-->0){
    int n, temp;
    cin>>n;
    
    vector<int> vec(3);
    for(int i=0; i<n; i++){
      cin>>temp;
      vec[temp]++;
    }
    
    for(int i=0; i<vec[0]; i++)
      cout<<"0 ";
    for(int i=0; i<vec[1]; i++)
      cout<<"1 ";
    for(int i=0; i<vec[2]; i++)
      cout<<"2 ";
    cout<<endl;
  }
  return 0;
}