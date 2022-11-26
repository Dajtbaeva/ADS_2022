// ababababcx
// a = ab; b = ab; c = ababcx; -> ab + ababcx = ab + ababcx;
// a = abab; b = abab; c = cx; -> abab + cx = abab + cx;
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

ull numWays(string s){
    vector<ull> res = prefixes(s);
    ull ans = 0;
    for(ull i = 1; i < s.size(); i++){
        ull len = i - res[i - 1];
        if(res[i - 1] == 0) continue;
        if((i / len) % 2 == 0 && i % len == 0) ans++;
    }
    return ans;
}


int main() {
	string s;
	cin >> s;
    cout << numWays(s);
}