#include <bits/stdc++.h>

using namespace std;

int main(){
    int n, x, y;
    string s, t;
    cin >> n;
    map<pair< pair<string, int>, pair<string, int> >, bool> m;
    while(n--){
        cin >> s >> x >> t >> y;
        pair<string, int> p1 = make_pair(s, x);
        pair<string, int> p2 = make_pair(t, y);
        m[make_pair(p1, p2)] = true;
    }
    map<pair< pair<string, int>, pair<string, int> >, bool>::iterator it;
    for(it = m.begin(); it != m.end(); it++){
        string names = (*it).first.first.first + " and " + (*it).first.second.first;
        int score = (*it).first.first.second + (*it).first.second.second;
        cout << names << " " << score << "\n";
    }
}