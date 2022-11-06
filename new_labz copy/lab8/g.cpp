// abracadabra
// 5
// 1 1
// 1 2
// 3 4
// 1 5
// 1 4

#include <bits/stdc++.h>

using namespace std;

long long MOD = 1e9 + 7;
long long X = 31;

long long getHash(string s) {
    long long hash = 0;
    long long curX = 1;
    for (int i = 0; i < s.size(); i++) {
        long long curHash = (s[i] - 'a' + 1) * curX % MOD;
        hash = (hash + curHash) % MOD;
        curX = (curX * X) % MOD;
    }
    return hash;
}

vector<long long> getPrefixHashes(string s) {
    vector<long long> hashes(s.size());
    long long curX = 1;
    for (int i = 0; i < s.size(); i++) {
        hashes[i] = (s[i] - 'a' + 1) * curX % MOD;
        if (i != 0) {
            hashes[i] = (hashes[i] + hashes[i - 1]) % MOD;
        }
        curX = (curX * X) % MOD;
    }
    return hashes;
}

vector<int> rabinKarp(string s, string t) {
    long long smallHash = getHash(t);
    vector<int> res;
    vector<long long> hashes = getPrefixHashes(s);
    for (int i = 0; i < s.size() - t.size() + 1; i++) {
        long long hashDif = hashes[i + t.size() - 1];
        if (i != 0) hashDif -= hashes[i - 1];
        if (hashDif < 0) hashDif += MOD;
        if (i != 0) smallHash = (smallHash * X) % MOD;
        if (smallHash == hashDif) {
            res.push_back(i);
        };
    }
    return res;
}

int main() {
    // freopen("input.txt", "r", stdin);
	// freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    string s;
    cin >> s;
    int n; cin >> n;
    for(int i = 0; i < n; i++){
        int l, r; cin >> l >> r;
        string t = s.substr(l - 1, r - l + 1);
        vector<int> res = rabinKarp(s, t);
        cout << res.size() << "\n";
    }
}
