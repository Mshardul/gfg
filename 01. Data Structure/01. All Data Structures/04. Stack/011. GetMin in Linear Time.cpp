#include<iostream>
#include<stack>

using namespace std;

//using additional stack - that modifies (if required) min at any point of push/pop, in linear time
void Push(stack<int> *st, stack<int> *min, int x){
  st->push(x);
  if(min->empty())
    min->push(x);
  else if(x<min->top())
    min->push(x);
  else
    min->push(min->top());
}

void Pop(stack<int> *st, stack<int> *min){
  st->pop();
  min->pop();
}

int GetMin(stack<int> min){
  return min.top();
}