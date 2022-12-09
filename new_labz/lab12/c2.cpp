#include <iostream>
#include <vector>
#include <queue>
using namespace std;

const int MAXN = 2e3+10;
const int INF = 1e9;

struct edge{
    int v, cost;
    edge(int _v, int _cost){
        v = _v;
        cost = _cost;
    }
};

vector<edge> E[MAXN];
void addedge(int u, int v, int w) {
    E[u].push_back(edge(v,w));
    E[v].push_back(edge(u,w));
}
bool vis[MAXN];
int dis[MAXN];

void SPFA(int s, int n) {
    for(int i = 0; i <= n; i++){
        vis[i] = false;
    }
    for(int i = 1; i <= n; i++)
        dis[i] = INF;
    vis[s] = true;
    dis[s] = 0;
    queue<int> que;
    while(!que.empty()) que.pop();
    que.push(s);
    while(!que.empty()) {
        int u = que.front();
        que.pop();
        vis[u] = false;
        for(int i = 0; i < E[u].size(); i++) {
            int v = E[u][i].v;
            int cost = E[u][i].cost;
            if(dis[v] > dis[u]+cost) {
                dis[v] = dis[u]+cost;
                if(!vis[v]) {
                    vis[v] = true;
                    que.push(v);
                }
            }
        }
    }
}

bool mps[MAXN][MAXN];
int main()
{
    int n, m;
    cin >> n >> m;
    int u, v;
    for(int i = 0; i < m; i++) {
        cin >> u >> v;
        addedge(u,v,1);
        mps[u][v] = mps[v][u] = true;
    }
    int ans1, ans2;
    SPFA(1,n);
    ans1 = dis[n];
    for(int i = 1; i <= n; i++)
        E[i].clear();
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n; j++) {
            if(i == j) continue;
            if(!mps[i][j]) {
                mps[i][j] = true;
                addedge(i,j,1);
                addedge(j,i,1);
            }
        }
    }
    SPFA(1,n);
    ans2 = dis[n];
    if(ans1==INF || ans2==INF)
        cout << -1 << endl;
    else
        cout << max(ans1,ans2) << endl;
    return 0;
}