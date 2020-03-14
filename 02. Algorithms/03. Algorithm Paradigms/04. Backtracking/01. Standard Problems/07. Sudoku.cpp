#include<iostream>
#include<vector>

using namespace std;

void Print2D(vector<vector<int> > sudoku){
	for(int i=0; i<9; i++){
		for(int j=0; j<9; j++)
			cout<<sudoku[i][j]<<" ";
		cout<<endl;
	}
}

bool isOkay(vector<vector<int> > sudoku, int row, int col, int val){
	int rowCount = 0;
	for(int i=0; i<col; i++)
		if(sudoku[row][i]==val)
			rowCount++;
	if(rowCount>0)
		return false;
		
	int colCount = 0;
	for(int i=0; i<row; i++)
		if(sudoku[i][col]==val)
			colCount++;
	if(colCount>0)
		return false;
	
	int sqCount = 0;
	int rowFrom = row/3;
	int colFrom = col/3;
	for(int i=0; i<3; i++){
		for(int j=0; j<3; j++){
			if(sudoku[rowFrom+i][colFrom+i]==val)
				sqCount++;
		}
	}
	if(sqCount>1)
		return false;

	return true;
}

bool Backtrack(vector<vector<int> > sudoku, vector<pair<int, int> > empty, int ind, int n){
	if(ind>n){
		Print2D(sudoku);
		return true;
	}
	for(int i=1; i<=9; i++){
		pair<int, int> p = empty[ind];
		int row = p.first;
		int col = p.second;
		if(isOkay(sudoku, row, col, i)){
			cout<<row<<" "<<col<<" "<<i<<endl;
			sudoku[row][col] = i;
			bool solved = Backtrack(sudoku, empty, ind+1, n);
			if(solved)
				return true;
		}else{
			continue;
		}
	}
	return false;
}

void solve(vector<vector<int> > sudoku){ //should be correct, didnt check
	vector<pair<int, int> > empty;
	for(int i=0; i<9; i++){
		for(int j=0; j<9; j++){
			if(sudoku[i][j]==0)
				empty.push_back(make_pair(i, j));
		}
	}
	int n = empty.size();
	bool solved = Backtrack(sudoku, empty, 0, n);
	if(solved)
		cout<<"solved";
	else
		cout<<"could not be solved";
	cout<<endl;
}

bool FindUnassignedLocation(int grid[N][N], int &row, int &col) {
	for (row = 0; row < N; row++)
		for (col = 0; col < N; col++)
			if (grid[row][col] == UNASSIGNED)
				return true;
	return false;
}  

bool SolveSudoku(int grid[N][N]) { //copied
	int row, col;
	if (!FindUnassignedLocation(grid, row, col))
		return true;
	for (int num = 1; num <= 9; num++) {
		if (isSafe(grid, row, col, num)) {
			grid[row][col] = num;
			if (SolveSudoku(grid))
				return true;
			grid[row][col] = UNASSIGNED;
		}
	}
	return false;
}

int main(int argc, char const *argv[]) {
	vector<vector<int> > sudoku;
	sudoku.resize(9, vector<int>(9));
	for(int i=0; i<9; i++)
		for(int j=0; j<9; j++)
			cin>>sudoku[i][j];
	solve(sudoku);
	return 0;
}