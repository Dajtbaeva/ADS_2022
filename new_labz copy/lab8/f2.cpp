#include <bits/stdc++.h>
#define ull unsigned long long

using namespace std;

class TrieNode {
public:
	bool isWord;
	TrieNode* child[26];

	TrieNode(){
		isWord = 0;
		for (int i = 0; i < 26; i++) {
			child[i] = 0;
		}
	}
};

ull ans(string str){
	TrieNode* head = new TrieNode();
	ull count = 0;
	for (int i = 0; i < str.length(); i++) {
		TrieNode* temp = head;

		for (int j = i; j < str.length(); j++) {
			if (temp->child[str[j] - 'a'] == NULL) {
				temp->child[str[j] - 'a'] = new TrieNode();
				temp->isWord = 1;
				count++;
			}
			temp = temp->child[str[j] - 'a'];
		}
	}

	return count;
}

int main(){
    string s; cin >> s;
	ull count = ans(s);
	cout << count;

	return 0;
}
