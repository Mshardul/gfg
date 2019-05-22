/* The structure of the class is
class QueueStack{
private:
  queue<int> q1;
  queue<int> q2;
public:
  void push(int);
  int pop();
};
 */
/* The method push to push element into the stack */
void QueueStack :: push(int x)
{
  while(!q2.empty()){
    q1.push(q2.front());
    q2.pop();
  }
  q1.push(x);
}
/*The method pop which return the element poped out of the stack*/
int QueueStack :: pop()
{
  while(q1.size()>1){
    q2.push(q1.front());
    q1.pop();
  }
  if(q1.size()==1){
    int x = q1.front();
    q1.pop();
    return x;
  }
  else{
    while(q2.size()>1){
      q1.push(q2.front());
      q2.pop();
    }
    if(q2.size()==1){
      int x = q2.front();
      q2.pop();
      return x;
    }
    else return -1;
  }
}