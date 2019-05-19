//assumption: no duplicate elements. Hence, using set. Otherwise, rank() is a better option.

#include<iostream>
#include<set>

using namespace std;

int main(int argc, char const *argv[]) {
  int t;
  cin>>t;
  
  while(t-->0){
    int n, k, temp;
    cin>>n;
  
    set<int> s;
    for(int i=0; i<n; i++){
      cin>>temp;
      s.insert(temp);
    }
    
    cin>>k;
    
    set<int>::iterator iter=s.begin();
    for(int i=0; i<k; i++)
      iter++;
    cout<<*iter<<endl;
  }
  return 0;
}