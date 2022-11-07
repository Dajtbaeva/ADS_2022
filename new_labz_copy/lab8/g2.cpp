#include <bits/stdc++.h>
#define ull unsigned long long

using namespace std;

const int d = 26;
vector<ull> search(string s, string pattern, ull q = 1e9 + 7) {
	ull p = 0, t = 0, h = 1, i, j;
	vector<ull> ans;
	for (i = 0; i < pattern.size() - 1; i++)
		h = (h * d) % q;

	for (i = 0; i < pattern.size(); i++) {
		p = (d * p + pattern[i]) % q;
		t = (d * t + s[i]) % q;
	}

	for (i = 0; i <= s.size() - pattern.size(); i++) {
		if (p == t) {
			for (j = 0; j < pattern.size(); j++) {
				if (s[i + j] != pattern[j]) break;
			}
			if (j == pattern.size()) {
				ans.push_back(i);
			}
		}

		if (i < s.size() - pattern.size()) {
			t = (d * (t - s[i] * h) + s[i + pattern.size()]) % q;
			if (t < 0) t += q;
		}
	}
	return ans;
}

string substrr(ull l, ull r, string s){
    string temp = "";
    for(int i = l - 1; i < r; i++){
        temp += s[i];
    }
    return temp;
}

int main() {
    // freopen("input.txt", "r", stdin);
	// freopen("output.txt", "w", stdout);
    string s;
    cin >> s;   
    ull n; cin >> n;
    for(ull i = 0; i < n; i++){
        ull l, r; cin >> l >> r;
        string t = substrr(l, r, s);
        vector<ull> res = search(s, t);
		if(!res.size()) cout << 1 << "\n";
        else cout << res.size() << "\n";
    }
}