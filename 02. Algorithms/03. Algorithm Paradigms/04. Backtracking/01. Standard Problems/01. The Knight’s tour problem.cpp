#include<iostream>
#include<vector>

using namespace std;

void Print2D(vector<vector<int> > vec){
	int n = vec.size();
	cout<<"--------------\n";
	for(int i=0; i<n; i++){
		int m = vec[i].size();
		for(int j=0; j<m; j++)
			cout<<vec[i][j]<<" ";
		cout<<endl;
	}
	cout<<"--------------\n";
}

bool Backtrack(vector<vector<int> > &dp, int i, int j, int n, vector<pair<int, int> > move, int cells){
	if(cells>(n*n))
		return true;
	for(int mv=0; mv<8; mv++){
		int x = i+(move[mv].first);
		int y = j+(move[mv].second);
		cout<<"in "<<i<<", "<<j<<"; looking for "<<x<<", "<<y<<endl;
		if(x>=0 && x<n && y>=0 && y<n && dp[x][y]==0){ //no repetition
			dp[x][y] = cells;
			bool check = Backtrack(dp, x, y, n, move, cells+1);
			if(check){
				return true;
			}else{
				dp[x][y] = 0;
			}
			Print2D(dp);
		}
	}
	return false;
}

void KnightTour(int n){
	int h[] = {1, -1, 1, -1, -2, 2, -2, 2};
	int v[] = {2, 2, -2, -2, -1, -1, 1, 1};
	vector<pair<int, int> > move;
	for(int i=0; i<8; i++)
		move.push_back(make_pair(h[i], v[i]));
	vector<vector<int> > dp;
	dp.resize(n, vector<int>(n, 0));
	dp[0][0] = 1;
	bool res = Backtrack(dp, 0, 0, n, move, 2);
	if(res==true)
		Print2D(dp);
}

int main(int argc, char const *argv[]) {
	int n;
	cin>>n;
	KnightTour(n);
	return 0;
}