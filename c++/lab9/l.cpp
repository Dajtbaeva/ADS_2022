#include <bits/stdc++.h>

using namespace std;

bool comp(pair<int, int> &p1, pair<int, int> &p2){
    if(p1.first == p2.first) return p1.second < p2.second;
    return p1.first < p2.first;
}

int main(){
    int n, x, y;
    cin >> n;
    map<int, int> m;
    for(int i = 0; i < n; i++){
        cin >> x >> y;
        int a = x + y;
        m[a] = i + 1;
    }
    vector<pair<int, int> > v(m.begin(), m.end());
    sort(v.begin(), v.end(), comp);
    vector<pair<int, int> > :: iterator it;
    for(it = v.begin(); it != v.end(); it++){
        cout << (*it).second << " ";
    }
}