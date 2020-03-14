#include<iostream>
#include<vector>

using namespace std;

bool isOverflow(vector<int> vec, int top1, int top2){
  if(top1==top2-1)
    return true;
  return false;
}
void PushInFirst(vector<int> vec, int *top1, int top2, int val){
  if(isOverflow(vec, *top1, top2)==true)
    return;
  vec[++(*top1)]=val;
}

void PushInSecond(vector<int> vec, int top1, int *top2, int val){
  if(isOverflow(vec, top1, *top2)==true)
    return;
  vec[--(*top2)]=val;
}

void PopFirst(int *top1){
  if(*top1==-1)
    return;
  (*(top1))--;
}

void PopSecond(int *top2, int n){
  if(*top2==n)
    return;
  (*(top2))++;
}

void PrintFirst(vector<int> vec, int top1){
  while(top1!=-1)
    cout<<vec[top1--]<<" ";
  cout<<endl;
}

void PrintSecond(vector<int> vec, int top2, int n){
  while(top2!=n)
    cout<<vec[top2++]<<" ";
  cout<<endl;
}

int main(int argc, char const *argv[]) {
  int n;
  cin>>n;
  
  vector<int> vec(n);
  int top1=-1, top2=n;
  return 0;
}