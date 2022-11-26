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

    void ans(vector<int> v, vector<int> w, int n, int m){
        int i = 0, j = 0, cnt = 0;
        while(i < n && j < m){
            if(v[i] == w[j]){
                cnt++;
                i++; j++;
            }else if(v[i] < w[j]) i++;
            else j++;
        }
        cout << cnt;
    }

    int main() {
        string s, t, k;
        cin >> s;
        cin >> t;
        cin >> k;
        vector<int> s1 = rabinKarp(s, k);
        vector<int> t1 = rabinKarp(t, k);
        // for(auto i : s1) cout << i << " ";
        // cout << "\n";
        // for(auto j : t1) cout << j << " ";
        ans(s1, t1, s1.size(), t1.size());

    }