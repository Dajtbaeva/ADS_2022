#include <bits/stdc++.h>
#define ll long long
using namespace std;

ll getHash(string s){
    size_t n = s.size();
    size_t pSize = s.size();
    ll p[pSize];
    ll mod = 1e9 + 7;
    p[0] = 1;
    for(int i = 1; i < pSize; i++){
        p[i] = (p[i - 1] * 11) % mod;
    }
    ll hash = 0;
    for(size_t i = 0; i < n; i++){
        hash = (hash + ((s[i] - 47) * p[i]) % mod) % mod;
    }
    return hash;
}

int main(){
    // freopen("input.txt", "r", stdin);
	// freopen("output.txt", "w", stdout);
    ll n; cin >> n;
    ll m = n * 2;
    vector<string> v;
    string s;
    map<string, bool> isExist;
    map<string, string> myHashes;
    for(ll i = 0; i < m; i++){
        cin >> s;
        string num = to_string(getHash(s));
        isExist[s] = true;
        myHashes[s] = num;
        v.push_back(s);
    }
    ll cnt = 0;
    for(auto c : v){
        if(isExist[myHashes[c]] && cnt < n){
            cnt++;
            cout << "Hash of string \"" << c << "\" is "<< myHashes[c] << "\n";
        }
    }
}