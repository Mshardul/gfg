// constraints: 1<=a[i]<=60

#include<iostream>
#include<vector>

using namespace std;

void Print(vector<int> freq){
  int ind=0;
  for(vector<int>::iterator iter=freq.begin(); iter!=freq.end(); iter++){
    if(*iter!=0)
      cout<<ind<<" "<<*iter<<endl;
    ind++;
  }
  cout<<endl;
}

void SortByFrequency(vector<int> freq){
  vector<int> ans;
  int max = 1;
  do{
    for(vector<int>::iterator iter=ans.begin(); iter!=ans.end(); iter++){
      for(int i=0; i<max; i++)
        cout<<(*iter)+1<<" ";
      freq[*iter] = 0;
    }
    ans.clear();
    
    max=1;
    
    for(int i=0; i<60; i++){ //get list of elements with max frequenct
      if(max<freq[i]){
        max = freq[i];
        ans.clear();
      }
      if(max==freq[i])
        ans.push_back(i);
    }
  }while(!ans.empty());
  cout<<endl;
}

int main(int argc, char const *argv[]) {
  int t;
  cin>>t;
  
  while(t-->0){
    int n, temp;
    cin>>n;
    
    vector<int> vec(59); //1<=vec[i]<=60
    for(int i=0; i<n; i++){
      cin>>temp;
      vec[temp-1]++;
    }
    
    SortByFrequency(vec);
  }
  return 0;
}