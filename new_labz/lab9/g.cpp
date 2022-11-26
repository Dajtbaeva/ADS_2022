#include <bits/stdc++.h>
#define ull unsigned long long

using namespace std;

vector<ull> prefixes(string s) {
	vector<ull> pip(s.size());
	for (ull i = 1; i < s.size(); i++) {
		ull j = pip[i - 1];
		while (j > 0 && s[i] != s[j]) j = pip[j - 1];
		if (s[i] == s[j]) j++;
		pip[i] = j;
	}
	return pip;
}
int main() {
	string s;
	cin >> s;
	vector<ull> res = prefixes(s);
	cout << s.size() - res.back();
}