#include <iostream>
using namespace std;

#define n 5

bool SetQueen(int a[][n], int i);
void Print(int a[][n]);
bool CheckDiagonal(int a[][n], int i, int j){
	// cout<<"checking diagonally at "<<i<<" "<<j<<endl;
	int x=1;
	int ti=i;
	int tj=j;
	while(ti-x>=0 && tj-x>=0){
		if(a[ti-x][tj-x]==1)
			return false;
		x++;
	}
	x=1;
	ti=i;
	tj=j;
	while(ti+x<n && tj-x>=0){
		if(a[ti+x][tj-x]==1)
			return false;
		x++;
	}
	x=1;
	ti=i;
	tj=j;
	while(ti-x>=0 && tj+x<n){
		if(a[ti-x][tj+x]==1)
			return false;
		x++;
	}
	return true;
}

bool CheckRow(int a[][n], int i, int j){
	// cout<<"checking row "<<i<<endl;
	for(int x=0; x<j; x++)
		if(a[i][x]==1)
			return false;
	return true;
}

bool CheckCol(int a[][n], int i, int j){
	// cout<<"checking col "<<j<<endl;
	for(int x=0; x<i; x++)
		if(a[x][j]==1)
			return false;
	return true;
}

bool canSet(int a[][n], int i, int j){
	cout<<"At "<<i<<": ";
	if(CheckDiagonal(a, i, j) && CheckRow(a, i, j) && CheckCol(a, i, j)){
		cout<<"setting queen at "<<j<<endl;
		return true;
	}
	cout<<"cant set queen"<<endl;
	return false;
}
bool ResetQueen(int a[][n], int i){
	if(i<0)
		return false;
	cout<<" Resetting queen at "<<i<<endl;
	int j;
	for(j=0; j<n; j++){
		if(a[i][j]==1){
			a[i][j]=0;
			break;
		}
	}
	j+=1;
	for(;j<n; j++){
		if(canSet(a, i, j)){
			a[i][j]=1;
			Print(a);
			return SetQueen(a, i+1);
		}
	}
	if(i>-1){
		Print(a);
		return ResetQueen(a, i-1);
	}
	return false;
}
bool SetQueen(int a[][n], int i){
	if(i>=n)
		return true;
	cout<<"Setting queen at "<<i<<endl;
	for(int j=0; j<n; j++){
		if(canSet(a, i, j)){
			a[i][j]=1;
			Print(a);
			return SetQueen(a, i+1);
		}
	}
	if(i>-1){
		Print(a);
		return ResetQueen(a, i-1);
	}
	return false;
}

void Print(int a[][n]){
	for(int i=0; i<n; i++){
		for(int j=0; j<n; j++)
			cout<<a[i][j]<<" ";
		cout<<endl;
	}
}

int main(int argc, char const *argv[])
{
	// n=4;
	// cin>>n;
	int a[n][n];
	for(int i=0; i<n; i++){
		for(int j=0; j<n; j++)
			a[i][j]=0;
	}
	Print(a);
	bool ans=SetQueen(a, 0);
	if(ans){
		cout<<"YIPPIE!! N-QUEEN MATRIX IS POSSIBLE FOR N="<<n<<endl;
		Print(a);
	}
	else
		cout<<"NOPE!! N-QUEEN MATRIX IS NOT POSSIBLE FOR N="<<n<<endl;
	return 0;
}