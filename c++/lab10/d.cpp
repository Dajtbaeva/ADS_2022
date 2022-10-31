#include <bits/stdc++.h>

using namespace std;

bool comp(pair<vector<int>, int> p1, pair<vector<int>, int> p2){
    if(p1.second == p2.second) return p1.first.size() < p2.first.size();
    return p1.second < p2.second;
}

int main(){
    int n, m, x, sumi = 0;
    cin >> n;
    vector<pair<vector<int>, int> > v;
    vector<int> w;
    while(n--){
        cin >> m;
        while(m--){
            cin >> x;
            w.push_back(x);
            sumi += x;
        }
        v.push_back(make_pair(w, sumi));
        w.clear();
        sumi = 0;
    }
    sort(v.begin(), v.end(), comp);

    for(int i = 0; i < v.size(); i++){
        for(int j = 0; j < v[i].first.size(); j++){
            cout << v[i].first[j] << " ";
        } cout << "\n";
    }
}