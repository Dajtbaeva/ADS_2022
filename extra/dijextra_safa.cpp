#include <bits/stdc++.h>
// n^2 + m
using namespace std;

int const MAXN = 1e5 + 5;
int const INF = 1e9;
vector<pair<int, int> > g[MAXN];
bool used[MAXN];
int d[MAXN];
int n, m;

void dijkstra(int s){
    for(int i = 1; i <= n; i++){
        d[i] = INF;
    }
    d[s] = 0;
    for(int i = 0; i < n; i++){
        int u = -1;
        for(int j = 1; j <= n; j++){
            if(!used[j] && (u == -1 || d[j]  < d[u])){
                u = j;
            }
        }
        if(d[u] == INF) break;
        used[u] = true;
        for(int j = 0; j < g[u].size(); j++){
            pair<int, int> p = g[u][j];
            int v = p.first, w = p.second;
            if(d[v] > d[u] + w){
                d[v] = d[u] + w;
            }
        }

    }
}

int main(){
    cin >> m >> n;
    for(int i = 0; i < n; i++){
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