#include <bits/stdc++.h>

using namespace std;

bool comp(pair<string, int> p1, pair<string, int> p2){
    if(p1.second == p2.second) p1.first > p2.first;
    return p1.second > p2.second;
}

int main(){
    freopen("input.txt", "r", stdin);
    int n, x;
    double sumi = 0;
    string s;
    cin >> n;
    map<string, int> m;
    while(n--){
        cin >> s >> x;
        if(m.find(s) == m.end()) m.insert(make_pair(s, x));
        else m[s] += x;
        sumi += x;
    }
    vector<pair<string, int> > v(m.begin(), m.end());
    sort(v.begin(), v.end(), comp);
    vector<pair<string, int> > :: iterator it;
    for(it = v.begin(); it != v.end(); it++){
        cout << (*it).first << " " << ((*it).second / sumi) * 100 << "%\n";
    }

}