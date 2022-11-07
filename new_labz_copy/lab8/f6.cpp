#include <bits/stdc++.h>
#define ull unsigned unsigned long long
using namespace std;

unsigned long long MOD = 1e9 + 7;
unsigned long long X = 256;

unsigned long long getHash(string s) {
    unsigned long long hash = 0;
    unsigned long long curX = 1;
    for (int i = 0; i < s.size(); i++) {
        unsigned long long curHash = (s[i] - 'a' + 1) * curX % MOD;
        hash = (hash + curHash) % MOD;
        curX = (curX * X) % MOD;
    }
    return hash;
}

vector<unsigned long long> getPrefixHashes(string s) {
    vector<unsigned long long> hashes(s.size());
    unsigned long long curX = 1;
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
    unsigned long long smallHash = getHash(t);
    vector<int> res;
    vector<unsigned long long> hashes = getPrefixHashes(s);
    for (int i = 0; i < s.size() - t.size() + 1; i++) {
        unsigned long long hashDif = hashes[i + t.size() - 1];
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
    string s; cin >> s;
    vector<vector<unsigned long long> > v; // l
    unordered_map<unsigned long long, unsigned long long> h; // d
    for(unsigned long long i = 0; i < s.size(); i++){
        unsigned long long a = 0;
        for(unsigned long long j = i; j < s.size(); j++){
            a = (a * X + s[j]) % MOD;

            // unsigned long long a = getHash(s.substr(j, s.size() - j));
            if(h.find(a) == h.end()){
                v.push_back({i, j});
                h[a] = 1;
            }
        }
    }
    cout << v.size();
    // for(auto i : v){
    //     for(auto j : i) cout << j << " ";
    //     cout << "\n";
    // } 
    
}