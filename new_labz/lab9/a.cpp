#include <bits/stdc++.h>
#define ull unsigned long long

using namespace std;

vector<ull> prefixes(string s) {
	vector<ull> pi(s.size());
	for (ull i = 1; i < s.size(); i++) {
		ull j = pi[i - 1];
		while (j > 0 && s[i] != s[j]) j = pi[j - 1];
		if (s[i] == s[j]) j++;
		pi[i] = j;
	}
	return pi;
}

bool knuth_morris_pratt(string txt, string pat) {
	string concat = pat + '#' + txt;
	vector<ull> pi = prefixes(concat);
	for (ull i = pat.size() + 1; i < concat.size(); i++) {
		if (pi[i] == pat.size()) {
			return true;
		}
	}
	return false;
}

int main() {
	string s, t;
	cin >> s >> t;
	string k = s;
	int res = 1;
	while (s.size() < t.size()) {
		s += k;
		res++;
	}
	if (knuth_morris_pratt(s, t)) {
		cout << res;
		return 0;
	}
	if (knuth_morris_pratt(s + k, t)) {
		cout << ++res;
		return 0;
	}
	cout << -1;	
}