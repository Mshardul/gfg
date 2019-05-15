#include<iostream>
#include<vector> //using vector instead of linked list - will function similar, except random access
#include<stack>

using namespace std;

struct node{
  int val;
  struct node *lc, *rc;
};

struct node * newNode(int x){
  struct node *temp = new struct node();
  temp->val = x;
  temp->lc = NULL;
  temp->rc = NULL;
  return temp;
}

struct llNode{
  int val;
  struct llNode *next;
};

struct llNode * newLLNode(int x){
  struct llNode *temp= new struct llNode();
  temp->val = x;
  temp->next = NULL;
  return temp;
}

void PrintLL(struct llNode *head){
  while(head!=NULL){
    cout<<head->val<<" ";
    head = head->next;
  }
  cout<<endl;
}

void AddLLNode(struct llNode *head, int x){
  struct llNode *temp = head;
  while(temp->next!=NULL)
    temp = temp->next;
  temp->next = newLLNode(x);
}


struct node * GetIthNode(struct llNode *head, int ind){
  for(int i=0; i<ind; i++)
    head = head->next;
  return newNode(head->val);
}

void ConstructCBTree(struct node *head, struct llNode *llHead, int n){
  int ind = 1;
  deque<struct node *> d;
  struct node *temp = NULL;
  d.push_back(head);
  while(ind<n){
    temp = d.front();
    if(temp->lc==NULL){
      temp->lc = GetIthNode(llHead, ind);
      d.push_back(temp->lc);
    }else{
      temp->rc = GetIthNode(llHead, ind);
      d.pop_front();
      d.push_back(temp->rc);
    }
    ind++;
  }
}

void PrintTree(struct node *head){
  if(head==NULL)
    return;
  // cout<<"left subtree of "<<head->val<<": \n";
  PrintTree(head->lc);
  cout<<head->val<<" ";
  // cout<<"right subtree of "<<head->val<<": \n";
  PrintTree(head->rc);
}
int main(int argc, char const *argv[]) {
  int n;
  cin>>n;
  
  int temp;
  
  vector<int> vec(n);
  for(int i=0; i<n; i++)
    cin>>vec[i];
    
  struct llNode *llHead = newLLNode(vec[0]);
  
  for(vector<int>::iterator iter=vec.begin()+1; iter!=vec.end(); iter++)
    AddLLNode(llHead, *iter);
  
  struct node *head = newNode(vec[0]);
  ConstructCBTree(head, llHead, n);
  
  cout<<"Inorder sequence:\n";
  PrintTree(head);
  cout<<endl;
  
  return 0;
}