#include<iostream>

using namespace std;

// something is wrong

// The functions should be written in a way that array become sorted in increasing order when above heapSort() is called.
// To heapify a subtree rooted with node i which is an index in arr[]. n is size of heap. This function  is used in above heapSort()

/*
void heapSort(int arr[], int n)  {
  buildHeap(arr, n);
  for (int i=n-1; i>=0; i--)  {
    swap(arr[0], arr[i]);
    heapify(arr, i, 0);
  }
} */

void printArray(int arr[], int size){
  for(int i=0; i<size; i++)
    cout<<arr[i]<<" ";
  cout<<endl;
}

void heapify(int arr[], int n, int i)  {
  int lIndex = (2*i)+1;
  int rIndex = (2*i)+2;
  
  int smallerEleInd = i;
  if(lIndex<=n && arr[smallerEleInd]>arr[lIndex])
    smallerEleInd = lIndex;
  if(rIndex<=n && arr[smallerEleInd]>arr[rIndex])
    smallerEleInd = rIndex;
  
  if(smallerEleInd!=i){
    swap(arr[i], arr[smallerEleInd]);
    heapify(arr, smallerEleInd, 0);
  }
}

void buildHeap(int arr[], int n)  { 
  for(int ind=n-1; ind>0; ind--){
    int i = ind;
    int p = (i-1)/2;
    while(i>0 && arr[i]<arr[p]){
      swap(arr[i], arr[p]);
      i = p;
      p = (i-1)/2;
    }
  }
  cout<<"printing in build heap\n";
  printArray(arr, n);
}

void heapSort(int arr[], int n){
  buildHeap(arr, n);
  cout<<"printing after build heap\n";
  printArray(arr, n);
  for(int i=n-1; i>=0; i--){
    swap(arr[0], arr[i]);
    heapify(arr, i, 0);
  }
  cout<<"printing after heapify\n";
  printArray(arr, n);
}



int main(int argc, char const *argv[]) {
  int arr[1000000], n, t, i;
  cin>>t;
  while(t-->0){
    cin>>n;
    for(int i=0; i<n; i++)
      cin>>arr[i];
    heapSort(arr, n);
    cout<<"printing last\n";
    printArray(arr, n);
  }
  return 0;
}