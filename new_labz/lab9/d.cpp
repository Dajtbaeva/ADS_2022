#include<bits/stdc++.h>
#define ull unsigned long long

using namespace std;

vector<ull> prefix_function (string s) {
	ull n = (ull) s.length();
	vector<ull> pi (n);
	for (ull i = 1; i < n; ++i) {
		ull j = pi[i-1];
		while (j > 0 && s[i] != s[j])
			j = pi[j - 1];
		if (s[i] == s[j])  ++j;
		pi[i] = j;
	}
	return pi;
}

int main() {
    string s; cin >> s;
    s[0] = tolower(s[0]);
    ull n; cin >> n;
    vector<string> res;
    ull mx_len = 1;
    for(ull i = 0; i < n; i++) {
        string c; cin >> c;
        c[0] = tolower(c[0]);
        string p = c + "#" + s;
        vector<ull> pi = prefix_function(p);
        c[0] = toupper(c[0]);
        if(pi.back() > mx_len) {
            mx_len = pi.back();
            res.clear();
            res.push_back(c);
        } else if(pi.back() == mx_len) {
            res.push_back(c);
        }
    }
    cout << res.size() << endl;
    for(string c: res)
        cout << c << endl;
}