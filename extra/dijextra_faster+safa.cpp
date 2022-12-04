#include <bits/stdc++.h>
using namespace std;
// m*logn
int const MAXN = 1e5 + 5;
int const INF = 1e9;
vector<pair<int, int> > g[MAXN];
bool used[MAXN];
set<pair<int, int> > setik;
int d[MAXN];
int n, m;

void dijkstra(int s){
    for(int i = 1; i <= n; i++){
        if(i == s) d[i] = 0;
        else d[i] = INF;
        setik.insert(make_pair(d[i], i));
    }
    d[s] = 0;
    for(int i = 0; i < n; i++){
        pair<int, int> p = *(setik.begin());
        setik.erase(p);
        int u = p.second, du = p.first;
        if(du == INF) break;


        for(int j = 0; j < g[u].size(); j++){
            p = g[u][j];
            int v = p.first, w = p.second;
            if(d[v] > d[u] + w){
                // pair<int, int> p2 = *(setik.find(make_pair(d[v], v)));
                setik.erase(make_pair(d[v], v));
                d[v] = d[u] + w;
                setik.insert(make_pair(d[v], v));
            }
        }

    }
}

int main(){
    cin >> n >> m;
    for(int i = 0; i < m; i++){
        int u, v, w;
        cin >> u >> v >> w;
        g[u].push_back(make_pair(v, w));
        g[v].push_back(make_pair(u, w));
    }
    dijkstra(1);
    for(int i = 1; i <= n; i++){
        cout << d[i] << " ";
    }
}

// 6 9
// 1 2 7
// 1 6 14
// 1 3 9
// 2 3 10
// 2 4 15
// 3 6 2
// 3 4 11
// 4 5 6
// 5 6 9
// 0 7 9 20 20 11 