#include<iostream>

using namespace std;

void Push(int[] stack, int n, int val, int *top){ //top tells the index of array top
  if(top==n-1){
    cout<<"Stack overflow\n";
    return;
  }
  stack[++(*top)] = val;
}

int Pop(int[] stack, int n, int *top){
  if(top==-1){
    cout<<"Stack underflow\n";
    return -1;
  }
  int val = arr[(*top)--];
  return val;
}

void Traverse(int[] stack, int n, int top){
  if(top==-1){
    cout<<"Stack underflow\n";
    return;
  }
  while(top>-1){
    cout<<stack[top--];
  }
  cout<<endl;
}