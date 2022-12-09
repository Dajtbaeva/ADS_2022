#include <bits/stdc++.h>

using namespace std;

const int INF = 1e9 + 7;
const int MAXI = 1e5;
int d[MAXI], n;
vector<pair<int, int> > g[MAXI];
set<pair<int, int> > st;

void dijkstra(int s){
    for(int i = 1; i <= n; i++){
        if(i == s) d[i] = 0;
        else d[i] = INF;
        st.insert(make_pair(d[i], i));
    }

    for(int i = 0; i < n; i++){
        pair<int, int> p = *(st.begin());
        st.erase(p);
        int u = p.second, du = p.first;
        if(du == INF) break;


        for(int j = 0; j < g[u].size(); j++){
            p = g[u][j];
            int v = p.first, w = p.second;
            if(d[v] > d[u] && d[v] > w){
                st.erase(make_pair(d[v], v));
                d[v] = max(d[u], w);
                st.insert(make_pair(d[v], v));
            }
        }

    }
}

int main(){
    int x, y;
    cin >> n;
    pair<int, int> cities[n];
    for(int i = 0; i < n; i++){
        cin >> x >> y;
        cities[i] = {x, y};
    }

    for(int i = 0; i < n; i++){
        for(int j = i + 1; j < n; j++){
            int w = abs(cities[i].first - cities[j].first) + abs(cities[i].second-cities[j].second);
            g[i + 1].push_back({j + 1, w});
            g[j + 1].push_back({i + 1, w});
        }
    }
    dijkstra(1);
    cout << d[n];
}