#include <bits/stdc++.h>

using namespace std;
vector<vector<int> > g;
vector<int> top_sort;
vector<bool> visited;

void dfs(int v){
    visited[v] = true;
    for(int i = 0; i < g[v].size(); i++){
        int u = g[v][i];
        if(!visited[u]) dfs(u);
    }
    top_sort.push_back(v);
}

int main(){
    int n, m;
    cin >> m >> n;
    visited.resize(m);
    g.resize(m);
    for(int i = 0; i < n; i++){
        int u, v;
        cin >> u >> v;
        u--; v--;
        g[u].push_back(v);
    }
    for(int i = 0; i < m; i++){
        if(!visited[i]) dfs(i);
    }
    reverse(top_sort.begin(), top_sort.end());
    
}