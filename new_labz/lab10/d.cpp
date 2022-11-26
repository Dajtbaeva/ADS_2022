#include <bits/stdc++.h>
using namespace std;

int n, m;
int const sz = 5005;
vector<int> g[sz];
int d[sz];
bool used[sz];
int color[5005];
queue<int> q;

void bfs(int s){
	for(int i = 1; i <= n; i++){
		used[i] = 0;
	}
	q.push(s);
	d[s] = 0;
	used[s] = 1;
	while(!q.empty()){
		int v = q.front();
		q.pop();
		for(int i = 0; i < g[v].size(); i++){
			int to = g[v][i];
			if(d[to] > d[v] + 1){
				d[to] = d[v] + 1;
				used[to] = 1;
				q.push(to);
			}
		}
	}
}


int main() {
	int type, v, k;
	cin >> n >> m >> k;
	for(int i = 0; i < m; i++){
		int u, w; cin >> u >> w;
		g[u].push_back(w);
		g[w].push_back(u);
	}
	for(int i = 1; i <= n; i++){
		d[i] = 1e9;
	}
	for(int i = 0; i < k; i++){
		cin >> type >> v;
		if(type == 1){
			if(color[v] != 1){
				bfs(v);
				color[v] = 1;
			}
		}else{
			if(d[v] == 1e9) cout << -1 << "\n";
			else cout << d[v] << "\n";
		}
	}

}