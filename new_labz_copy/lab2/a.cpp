// http://78.140.223.58/cgi-bin/new-client?contest_id=302

#include <bits/stdc++.h>

using namespace std;

bool comp(pair<int, int> &p1, pair<int, int> & p2){
    if(p1.first == p2.first) return p1.second < p2.second;
    else return p1.first < p2.first;
}

int main(){
    int n, x, k;
    cin >> n;
    vector<int> v;
    for(int i = 0; i < n; i++){
        cin >> x;
        v.push_back(x);
    }
    cin >> k;
    vector<pair<int, int> > w;
    for(int i = 0; i < n; i++){
        w.push_back(make_pair(abs(v[i] - k), i));
    }
    sort(w.begin(), w.end(), comp);
    vector<pair<int, int> > :: iterator it;
    cout << w[0].second;
}