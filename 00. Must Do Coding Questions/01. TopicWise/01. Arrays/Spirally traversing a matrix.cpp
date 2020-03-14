#include<iostream>
#include<vector>
#include<math.h>
using namespace std;

void Print(vector<int> vec){
  for(vector<int>::iterator iter=vec.begin(); iter!=vec.end(); iter++)
    cout<<*iter<<" ";
  cout<<endl;
}
void SpiralTraversal(vector< vector<int> > mat, int m, int n){
  int row = m;
  int col = n;
  
  // for(int i=0; i<row; i++){
  //   for(int j=0; j<col; j++)
  //     cout<<mat[i][j]<<" ";
  //   cout<<endl;
  // }
  
  int hRow = row/2;
  if(row%2==1)
    hRow++;
  
  int hCol = col/2;
  if(col%2==1)
    hCol++;
    
  // cout<<hRow<<" "<<hCol<<endl;
  vector<int> vec;
  int i=0, j=0;
  while(i<hRow && j<hCol){
    for(int k=j; k<col-j; k++)
      cout<<mat[i][k]<<" ";
    // cout<<endl;
    for(int k=i+1; k<row-i; k++)
      cout<<mat[k][col-1-j]<<" ";
    // cout<<endl;
    if((i!=(hRow-1)) || (row%2==0)){
      for(int k=col-2-j; k>=j; k--)
        cout<<mat[row-1-i][k]<<" ";
    }
    // cout<<endl;
    if((j!=(hCol-1)) || (col%2==0)){
      for(int k=row-2-i; k>i; k--)
        cout<<mat[k][j]<<" ";
    }
    // cout<<endl;
    // cout<<"----------\n";
    i++; j++;
  }
  cout<<endl;
}
int main(int argc, char const *argv[]) {
  int t;
  cin>>t;
  
  while(t-->0){
    int m, n;
    cin>>m>>n;
    
    vector <vector<int> > mat;
    mat.resize(m,vector<int>(n));
    
    for(int i=0; i<m; i++){
      for(int j=0; j<n; j++)
        cin>>mat[i][j];
    }
    
    SpiralTraversal(mat, m, n);
  }
  return 0;
}