#include <bits/stdc++.h>
using namespace std;

vector<vector<int> > g;
vector<bool> visited;
bool flazhochek;
int s, f;

void dfs(int v) {
	if (v == f) {
		flazhochek = true;
		return;
	}
	visited[v] = true;
	for (int i = 0; i < g[v].size(); i++) {
		int to = g[v][i];
		if (!visited[to]) {
			dfs(to);
		}
	}
}

int main() {
    int n, m;
	cin >> m >> n;
	g.resize(m);
	visited.resize(m);
	for (int i = 0; i < n; i++) {
		int u, v;
		cin >> u >> v;
		u--; v--;
		g[u].push_back(v);
		g[v].push_back(u);
	}
	cin >> s >> f;
	s--; f--;
	dfs(s);
	cout << (flazhochek ? "YES" : "NO");
}