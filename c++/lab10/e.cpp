#include <bits/stdc++.h>

using namespace std;

int main(){
    int n, k, x;
    double sumi = 0;
    string s;
    cin >> n;
    map<string, int> m;

    while(n--){
        cin >> k;
        while(k--){
            cin >> s >> x;
            sumi += x;
            if(m.find(s) == m.end()) m[s] = x;
            else m[s] += x;
        }
    }
    vector<pair<string, int> > v(m.begin(), m.end());
    for(int i = 0; i < v.size(); i++){
        cout << v[i].first << " " << (v[i].second / sumi) * 100 << "\n";
    }
}