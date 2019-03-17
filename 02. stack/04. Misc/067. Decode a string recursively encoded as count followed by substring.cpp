#include <iostream>
#include <stdlib.h>
using namespace std;

//assuming single digit numeric values

string Decode(string str){

	cout<<"got "<<str<<" ";
	string ans="";
	string num="";

	int st;
	
	for(int i=0; i<str.length(); i++){
		if(str[i]>='a' && str[i]<='z')
			ans+=str[i];
		else if(str[i]>='0' && str[i]<='9')
			num+=str[i];
		else if(str[i]=='['){
			st=i;
			break;
		}
	}

	int n = atoi(num);
	string newStr = str.substr(st, n-1);
	string getIt = Decode(newStr);
	for(int i=0; i<n; i++){
		ans+=getIt;
	}

	cout<<"converted to "<<ans<<endl;
	return ans;

}

int main(int argc, char const *argv[])
{
	string str;
	cin>>str;

	string ans = Decode(str);
	cout<<ans;
	return 0;
}