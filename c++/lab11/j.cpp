#include <bits/stdc++.h>

using namespace std;

bool comp(pair<double, pair<int, int> > &p1, pair<double, pair<int, int> > p2){
    return p1.first < p2.first;
}

int main(){
    int x1, y1, n, x2, y2;
    cin >> x1 >> y1;
    cin >> n;
    vector<pair<double, pair<int, int> > > v;
    for(int i = 0; i < n; i++){
        cin >> x2 >> y2;
        double s = sqrt(pow((x2 - x1), 2) + pow((y2 - y1), 2));
        v.push_back(make_pair(s, make_pair(x2, y2)));
    }
    sort(v.begin(), v.end(), comp);
    vector<pair<double, pair<int, int> > > :: iterator it;
    for(it = v.begin(); it != v.end(); it++){
        cout << (*it).second.first << " " << (*it).second.second << "\n";
    }
}