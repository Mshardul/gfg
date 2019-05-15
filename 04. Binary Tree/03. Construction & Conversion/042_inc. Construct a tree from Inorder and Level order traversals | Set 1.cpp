#include<iostream>
#include<vector>

using namespace std;

struct node{
  int val;
  struct node *lc, *rc;
};

struct node *newNode(int x){
  struct node *temp = new struct node();
  temp->val = x;
  temp->lc = NULL;
  temp->rc = NULL;
  return temp;
}

void ConstructTree(struct node **head, vector<int> in, int lIn, int rIn, vector<int> level, int lLevel, int rLevel){
  int headVal = level[lLevel];
  struct node *tempHead = newNode(headVal);
  cout<<headVal<<": ";
  int ind = find(in.begin(), in.end(), headVal) - in.begin();
  if(ind>lIn){
    cout<<"left of "<<headVal<<" in "<<lIn<<" "<<ind<<" "<<lLevel+1<<" "<<rLevel<<endl;
    ConstructTree(&((*head)->lc), in, lIn, ind, level, lLevel+1, rLevel);
  }
  if(ind<rLevel){
    int skip = 1;
    if(ind>lIn)
      skip += 1;
    cout<<"right of "<<headVal<<" in "<<ind+1<<" "<<rLevel<<" "<<lLevel+skip<<" "<<rLevel<<endl;
    ConstructTree(&((*head)->rc), in, ind+1, rLevel, level, lLevel+skip, rLevel);
  }
}

int main(int argc, char const *argv[]) {
  int n;
  cin>>n;
  
  vector<int> in(n);
  vector<int> level(n);
  
  for(int i=0; i<n; i++)
    cin>>in[i];
  for(int i=0; i<n; i++)
    cin>>level[i];
    
  struct node * head = NULL;
  
  ConstructTree(&head, in, 0, n, level, 0, n);
  return 0;
}