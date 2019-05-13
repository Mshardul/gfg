#include<iostream>
#include<vector>
#include<deque>

using namespace std;

struct node{
  int val;
  struct node *lc, *rc;
};

struct node *newNode(int x){
  struct node * temp = new struct node();
  temp->val = x;
  temp->lc = NULL;
  temp->rc = NULL;
  return temp;
}

void GetVec(vector<struct node *> *treeVec, deque<struct node *> temp){
  if(temp.empty())
    return;
  int n = temp.size();
  struct node * t;
  for(int i=0; i<n; i++){
    t = temp.front();
    temp.pop_front();
    if(t->lc!=NULL)
      temp.push_back(t->lc);
    if(t->rc!=NULL)
      temp.push_back(t->rc);
    treeVec->push_back(t);
  }
  GetVec(treeVec, temp);
}

int GetInd(vector<struct node *> treeVec, int val){
  int ind = 0;
  for(vector<struct node *>::iterator iter = ((treeVec).begin()); iter<(treeVec).end(); iter++){
    if((*iter)->val==val)
      return ind;
    ind++;
  }
  return -1;
}

void ReversePath(vector<struct node *> *treeVec, int ind){
  cout<<ind<<endl;
  if(treeVec->empty())
    return;
  vector<struct node *> temp;
  vector<int> indices;
  while(ind!=0){
    indices.push_back(ind);
    temp.push_back((*treeVec)[ind]);
    ind = (ind%2==1)?ind+1:ind;
    ind = (ind/2)-1;
  }
  
  indices.push_back(0);
  temp.push_back((*treeVec)[0]);
  
  int n = indices.size();
  struct node *t;
  for(int i=0; i<n; i++){
    ((*treeVec)[indices[n-1-i]]) = temp[i];
    // cout<<indices[i]<<": "<<(*treeVec)[indices[i]]->val<<endl;
  }
}

void PrintTree(vector<struct node *> treeVec){
  cout<<"printing vector\n";
  for(vector<struct node *>::iterator iter = treeVec.begin(); iter<treeVec.end(); iter++)
    cout<<(*iter)->val<<" ";
  cout<<endl;
}

int main(int argc, char const *argv[]) {
  struct node *head = newNode(1);
  head->lc = newNode(2); 
  head->rc = newNode(3); 
  head->lc->lc = newNode(4); 
  head->lc->rc = newNode(5); 
  head->rc->lc = newNode(6); 
  head->rc->rc = newNode(7); 
  head->lc->lc->lc = newNode(8); 
  head->lc->lc->rc = newNode(9); 
  head->lc->rc->lc = newNode(3); 
  head->lc->rc->rc = newNode(1); 
  head->rc->lc->lc = newNode(4); 
  head->rc->lc->rc = newNode(2); 
  head->rc->rc->lc = newNode(7); 
  head->rc->rc->rc = newNode(2); 
  head->lc->rc->lc->lc = newNode(16); 
  head->lc->rc->lc->rc = newNode(17); 
  head->rc->lc->rc->lc = newNode(18); 
  head->rc->rc->lc->rc = newNode(19);
  
  vector<struct node *> treeVec;
  
  deque<struct node *> temp;
  temp.push_back(head);
  
  GetVec(&treeVec, temp);
  
  PrintTree(treeVec);
  
  int val;
  cin>>val;
  
  int ind = GetInd(treeVec, val);
  if(ind==-1){
    cout<<"no such value found\n";
    return 0;
  }
  
  ReversePath(&treeVec, ind);
  
  PrintTree(treeVec);
  
  return 0;
}