#include <bits/stdc++.h>
#define ull unsigned long long
using namespace std;

void printSubstrings(string s){
	unordered_set<string> us;
	for (ull  i = 0; i < s.size(); ++i) {
		string ss = "";
		for (ull j = i; j < s.size(); ++j) {
			ss = ss + s[j];
			us.insert(ss);
		}
	}
	cout << us.size();
}

// Driver code
int main(){
	string str; cin >> str;
	printSubstrings(str);
	return 0;
}
