//assuming only lower case alphabets

#include<iostream>
#include<map>

using namespace std;

struct node{
	int c;
	struct node *lc, *rc;
}

struct node * newNode(int c){
	struct node *temp = new struct node();
	temp->x = x;
	temp->lc = NULL;
	temp->rc = NULL;
	return temp;
}

string huffman(string s){
	vector<int> freq(26, 0);
	for(char ch: s)
		freq[ch-'a']++;
	map<struct node*, char> nodes;
	
	int d = 0;
	for(int i=0; i<26; i++){
		if(freq[i]!=0){
			struct node *temp = newNode(freq[i]);
			d++;
			nodes.insert(make_pair(temp, 'a'+i));
		}
	}
	
	while(d>1){
		pair<struct node*, freq> f = nodes.at(0);
		pair<struct node*, freq> s = nodes.at(1);
	}
}

int main(int argc, char const *argv[]) {
	string s;
	cin>>s;
	
	cout<<huffman(s)<<endl;
	return 0;
}