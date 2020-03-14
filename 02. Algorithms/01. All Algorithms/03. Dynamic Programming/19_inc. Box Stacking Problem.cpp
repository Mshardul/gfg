#include<iostrem>
#include<vector>

using namespace std;

int stack(vector<int> h, vector<int> w, vector<int> l, int n){
	
}

int main(int argc, char const *argv[]) {
	int n;
	cin>>n;
	vector<int> h(n);
	vector<int> w(n);
	vector<int> l(n);
	for(int i=0; i<n; i++)
		cin>>h[i]>>w[i]>>l[i];
	
	stack(h, w, l, n);
	return 0;
}