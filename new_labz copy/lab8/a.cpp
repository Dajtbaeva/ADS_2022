#include <bits/stdc++.h>

using namespace std;

unsigned long long MOD = 1e9 + 7;
unsigned long long X = 11;

string to_stringg(unsigned long long h){
    string res = "";
    while(h > 0){
        res = char((h % 10) + 48) + res;
        h /= 10;
    }
    return res;
}

unsigned long long getHash(string s) {
    unsigned long long hash = 0;
    unsigned long long curX = 1;
    for (int i = 0; i < s.size(); i++) {
        unsigned long long curHash = ((s[i] - 47) * curX) % MOD;
        hash = (hash + curHash) % MOD;
        curX = (curX * X);
    }
    return hash;
}

int main() {
    cout << getHash("3383080447314675044643313") << "\n"; // vyvodit: 337965992 -> dolzhno: 425675346
    return 0;
    int n; cin >> n;
    int m = n * 2;
    vector<string> all;
    for(int i = 0; i < m; i++){
        string s; cin >> s;
        all.push_back(s);
    }
    for(int i = 0; i < all.size(); i++){
        string h = to_stringg(getHash(all[i]));
        vector<string> :: iterator it = find(all.begin(), all.end(), h);
        if (it != all.end()){
            cout << "Hash of string \"" << all[i] << "\" is " << h << "\n";
            // all.erase(it); 
            // all.erase(all.begin() + i);
            // i+=2;
        }
    }
}