#include <bits/stdc++.h>

using namespace std;

const int MAXI = 2e3 + 5;
const int INF = 1e9;
bool used[MAXI];
bool mm[MAXI][MAXI];
int d[MAXI];

struct Edge{
    int v, c;

    Edge(int v, int c){
        this->v = v;
        this->c = c;
    }
};
vector<Edge> E[MAXI];

void insert_edge(int u, int v, int w){
    E[u].push_back(Edge(v, w));
    E[v].push_back(Edge(u, w));
}

void ans(int s, int n){
    for(int i = 0; i <= n; i++) used[i] = 0;
    for(int i = 1; i <= n; i++) d[i] = INF;
    used[s] = 1;
    d[s] = 0;

    queue<int> q;
    while(!q.empty()) q.pop();
    q.push(s);
    while(!q.empty()){
        int u = q.front();
        q.pop();
        used[u] = 0;

        for(int i = 0; i < E[u].size(); i++){
            int v = E[u][i].v;
            int c = E[u][i].c;
            if(d[v] > d[u] + c){
                d[v] = d[u] + c;
                if(!used[v]){
                    used[v] = 1;
                    q.push(v);
                }
            }
        }
    }

}
int main(){
    int n, m, u, v, res = 0, rez = 0; cin >> n >> m;
    for(int i = 0; i < m; i++){
        cin >> u >> v;
        insert_edge(u, v, 1);
        mm[u][v] = 1;
        mm[v][u] = 1;
    }
    ans(1, n);
    res = d[n];
    for(int i = 1; i <= n; i++) E[i].clear();

    for(int i= 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            if(i == j) continue;
            if(!mm[i][j]){
                mm[i][j] = 1;
                insert_edge(i, j, 1);
                insert_edge(j, i, 1);
            }
        }
    }
    ans(1, n);
    rez = d[n];
    (res == INF || rez == INF) ? cout << -1 << "\n" : cout << max(res, rez) << "\n";
}