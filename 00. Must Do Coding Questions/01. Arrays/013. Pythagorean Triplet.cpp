//cant think of sol with lesser time complexity

#include<iostream>
#include<vector>
#include<algorithm>
#include<math.h>
using namespace std;

bool GetPythagoreanTriplet(vector<int> vec, int n){
  sort(vec.begin(), vec.end());
  for(int i=0; i<n; i++){
    for(int j=i+1; j<n; j++){
      int k = (vec[i]*vec[i])+(vec[j]*vec[j]);
      int l = sqrt(k);
      if((l*l==k) && (find(vec.begin(), vec.end(), l)!=vec.end())){
        cout<<vec[i]<<" "<<vec[j]<<" "<<l<<endl;
        return true;
      }
    }
  }
  return false;
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
      
    if(GetPythagoreanTriplet(vec, n))
      cout<<"Yes";
    else
      cout<<"No";
    cout<<endl;
  }
  return 0;
}