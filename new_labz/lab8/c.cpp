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
    string s, t;
    cin >> s;
    int n; cin >> n;
    vector<int> ans(s.size());
    for(int i = 0; i < n; i++){
        cin >> t;
        vector<int> v = rabinKarp(s, t);
        int sz = t.size();
        for(auto i : v) fill(ans.begin() + i, ans.begin() + i + sz, 1);
    }
    for(auto i : ans){
        if(!i){
            cout << "NO";
            return 0;
        }
    }
    cout << "YES";
}