#include <bits/stdc++.h>

using namespace std;

bool pal(vector<char> w){
    vector<char> vv(w.begin(), w.end());
    int cnt = 0;
    reverse(vv.begin(), vv.end());
    for(int i = 0; i < w.size(); i++){
        if(w[i] == vv[i]) cnt++;
    }
    if(cnt == w.size()) return true;
    else return false;
}

int main(){
    string s;
    cin >> s;
    vector<char> v;
    for(int i = 0; i < s.size(); i++){
        v.push_back(s[i]);
    }
    sort(v.begin(), v.end());
    bool ok = false;
    while(next_permutation(v.begin(), v.end())){
        if(pal(v)){
            ok = true;
            cout << "ZA WARUDO TOKI WO TOMARE";
            return 0;
        }
    }
    if(!ok) cout << "JOJO";
}