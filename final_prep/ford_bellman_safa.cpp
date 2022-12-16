#include <bits/stdc++.h>

using namespace std;
int n, m;
int const MAXN = 1e5 + 5;
int const INF = 1e9;
int d[MAXN];

struct Edge{
    int a, b, w;
    Edge(){}
    Edge(int _a, int _b, int _w){
        a = _a;
        b = _b;
        w = _w;
    }
}; 

Edge e[MAXN];

void ford_bellman(int s){
    for(int i = 1; i <= n; i++){
        d[i] = INF;
    }
    d[s] = 0;
    for(int i =0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(d[e[j].b] > d[e[j].a] + e[j].w){
                d[e[j].b] = d[e[j].a] + e[j].w;
            }
        }
    }
}
int main(){
    cin >> n >> m;
    for(int i = 0; i < m; i++){
        int u, v, w; cin >> u >> v >> w;
        e[2 * i] = Edge(u, v, w);
        e[2 * i + 1] = Edge(v, u, w);
    }
    m *= 2;

    ford_bellman(1);
    for(int i = 1; i <= n; i++){
        cout << d[i] << " ";
    }
}