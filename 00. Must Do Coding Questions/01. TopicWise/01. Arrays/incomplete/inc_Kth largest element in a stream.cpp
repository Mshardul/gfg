#include<iostream>
#include<vector>
#include<set>
#include<iterator>

using namespace std;

set<int>::reverse_iterator GetKthLargestEle(set<int> s, int k){
  cout<<"GetKthLargestEle "<<s.size();
  set<int>::reverse_iterator iter = s.rbegin();
  for(int i=1; i<k; i++){
    cout<<i<<" "<<*iter<<endl;
    iter++;
  }
  return iter;
}

void GetEle(vector<int> vec, int n, int k){ //assuming no duplicate element
  vector<int> ans(n);
  set<int> s;
  
  int i=0;
  
  while(i<k-1){
    ans[i] = -1;
    s.insert(vec[i]);
    i++;
  }
  
  while(i<n){ //i=k-1
    s.insert(vec[i]);
    // set<int>::reverse_iterator iter = GetKthLargestEle(s, k);
    set<int>::iterator iter = s.begin();
    // cout<<*iter;
    ans[i] = *iter;
    s.erase(s.find(vec[i-k+1]));
    i++;
  }
  
  for(vector<int>::iterator iter=ans.begin(); iter!=ans.end(); iter++)
    cout<<*iter<<" ";
  cout<<endl;
}

int main(int argc, char const *argv[]) {
  int t;
  cin>>t;
  
  while(t-->0){
    int n, k, temp;
    cin>>k>>n;
    
    vector<int> vec(n);
    
    for(int i=0; i<n; i++){
      cin>>vec[i];
    }
    
    // Temp(vec, n);
    GetEle(vec, n, k);
  }
  return 0;
}