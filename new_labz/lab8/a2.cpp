#include <bits/stdc++.h>
#define ull long long
using namespace std;

ull MOD = 1e9 + 7;
ull X = 11;

ull getHash(string s) {
    ull hash = 0;
    ull curX = 1;
    for (size_t i = 0; i < s.size(); i++) {
        ull curHash = ((s[i] - 47) * curX) % MOD;
        hash = (hash + curHash) % MOD;
        curX = (curX * X);
    }
    return hash;
}

int main() {
    // cout << getHash("3383080447314675044643313") << "\n"; // vyvodit: 337965992 -> dolzhno: 425675346
    // return 0;
    ull n; cin >> n;
    ull m = n * 2;
    vector<string> all;
    for(ull i = 0; i < m; i++){
        string s; cin >> s;
        all.push_back(s);
    }
    for(ull i = 0; i < all.size(); i++){
        string h = to_string(getHash(all[i]));
        vector<string> :: iterator it = find(all.begin(), all.end(), h);
        if (it != all.end()) cout << "Hash of string \"" << all[i] << "\" is " << h << "\n";
    }
}
