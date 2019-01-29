#include <iostream>
using namespace std;

//T(n): O(n); S(n): O(1);
int main(int argc, char const *argv[])
{
	int n;
	cin>>n;
	int a[n], b[n], c[n];
	for(int i=0; i<n; i++)
		cin>>a[i];
	for(int i=0; i<n; i++)
		cin>>b[i];
	for(int i=0; i<n; i++)
		cin>>c[i];
	sort(a, a+n);
	sort(b, b+n);
	sort(c, c+n);
	int ind_a=0, ind_b=0, ind_c=0, x, y, z;
	int diff=INT_MAX;
	while(ind_a<n && ind_b<n && ind_c<n){
		int sum=a[ind_a]+b[ind_b]+c[ind_c];

		int min_=min(a[ind_a], min(b[ind_b], c[ind_c]));
		int max_=max(a[ind_a], max(b[ind_b], c[ind_c]));

		if(min_==a[ind_a])
			ind_a++;
		else if(min_==b[ind_b])
			ind_b++;
		else
			ind_c++;

		if(diff>max_-min_){
			diff=max_-min_;

			x=max_;
			y=sum-(max_+min_);
			z=min_;
		}
	}

	cout<<x<<" "<<y<<" "<<z<<endl;
	return 0;
}