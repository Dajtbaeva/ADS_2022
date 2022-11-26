#include <bits/stdc++.h>
#define ull unsigned long long

using namespace std;

vector<ull> prefixFunction(string s) {
	vector<ull> pi(s.length());
	for (ull i = 1; i < s.length(); i++) {
		ull j = pi[i - 1];
		while (j > 0 && s[i] != s[j]) j = pi[j - 1];
		if (s[i] == s[j]) j++;
		pi[i] = j;
	}
	return pi;
}

vector<ull> findSubstrings(string txt, string pat) {
	vector<ull> ans;
	string concat = pat + '#' + txt;
	vector<ull> pi = prefixFunction(concat);
	for (ull i = pat.size() + 1; i < concat.size(); i++) {
		if (pi[i] == pat.size()) {
			ans.push_back(i - 2 * pat.size());
		}
	}
	return ans;
}

int main() {
	ull n;
	cin >> n;
	while (n--) {
		string s;
		ull m;
		cin >> s >> m;
		vector<ull> pi = prefixFunction(s);
		ull k = s.size() - pi.back();
		cout << k * (m - 1) + s.size() << endl;
	}
	return 0;
}