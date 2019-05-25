#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>

using namespace std;
/*
GetMedian(vector<int> vec, int n){ //using algorithm
  vector<int> heap = vec[0];
  make_heap(heap.begin(), heap.end()); //maxHeap, by default.
  for(int i=1; i<n; i++){
    heap.push_heap(vec[i]);
  }
}
*/
void GetMedian(vector<int> vec, int n){ //using priority_queue
  
  if(n==1)
    cout<<vec[0]<<endl;
  int a = vec[0];
  int b = vec[1];
  
  priority_queue<int, vector<int> > heapMax; //maxheap of elements<median
  priority_queue<int, vector<int>, greater<int> > heapMin; //minheap of elements>median
  
  if(a<b){
    heapMax.push(a);
    heapMin.push(b);
  }else{
    heapMax.push(b);
    heapMin.push(a);
  }
  
  cout<<vec[0]<<endl<<(vec[0]+vec[1])/2<<endl;
  
  int ans;
  
  for(int i=2; i<n; i++){
    if(heapMax.top()>=vec[i]){
      heapMax.push(vec[i]);
      if((heapMax.size()-heapMin.size())>1){
        int temp = heapMax.top();
        heapMax.pop();
        heapMin.push(temp);
      }
    }else if(heapMin.top()<=vec[i]){
      heapMin.push(vec[i]);
      if((heapMin.size()-heapMax.size())>1){
        int temp = heapMin.top();
        heapMin.pop();
        heapMax.push(temp);
      }
    }else{
      if(heapMin.size()<heapMax.size())
        heapMin.push(vec[i]);
      else
        heapMax.push(vec[i]);
    }
    
    if(heapMax.size()>heapMin.size())
      cout<<heapMax.top()<<endl;
    else if(heapMin.size()>heapMax.size())
      cout<<heapMin.top()<<endl;
    else
      cout<<(heapMin.top()+heapMax.top())/2<<endl;
  }
}

int main(int argc, char const *argv[]) {
  int n;
  cin>>n;
  
  vector<int> vec(n);
  for(int i=0; i<n; i++){
    cin>>vec[i];
  }
  
  GetMedian(vec, n);
  cout<<endl;
  
  return 0;
}