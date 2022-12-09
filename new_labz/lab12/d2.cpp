#include <iostream>
#include <set>
#include <vector>
#include <algorithm>
using namespace std;

const int MAXN = 1e5 + 5;
const int INF = 1e9;

vector<pair<int, int> > g[MAXN];
int d[MAXN];
int n;
set<pair<int, int> > setik;

void dijkstra(int s){
    for(int i = 1; i <= n; i++){
        if(i == s) d[i] = 0;
        else{d[i] = INF;}
        setik.insert(make_pair(d[i], i));
    }

    for(int i = 0 ; i < n; i++){
        pair<int, int> p = *(setik.begin());
        setik.erase(p);

        int u = p.second;
        int du = p.first;

        if(du == INF) break;

        for(int j = 0; j< g[u].size(); j++){
            p = g[u][j];
            int v = p.first, w = p.second;
            if(d[v] > w && d[v] > d[u]){
                setik.erase(make_pair(d[v], v));
                d[v] = max(d[u], w);
                setik.insert(make_pair(d[v], v));
            }
        }
    }
}

int main(){
    cin >> n;
    pair<int, int> city[n];
    for(int i = 0; i < n ; i++){
        int x, y; cin >> x >> y;
        city[i] = make_pair(x, y);
    }

    for(int i = 0 ; i < n; i++){
        for(int j = i+1; j < n; j++){
            int w = abs(city[i].first - city[j].first) + abs(city[i].second-city[j].second);
            g[i+1].push_back(make_pair(j+1, w));
            g[j+1].push_back(make_pair(i+1, w));
            //cout << i << "->" << j << ":" << w << " ";
        }
    }
    dijkstra(1);
    // for(int i = 1; i <= n; i++){
    //     cout << d[i] << " ";
    // }
    cout << d[n];


    return 0;
}