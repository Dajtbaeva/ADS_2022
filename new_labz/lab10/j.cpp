#include <bits/stdc++.h>
using namespace std;
#define ull unsigned long long

ull m, n, cnt;
vector<vector<ull> > g;
vector<bool> visited;

void dfs(ull v) {
	visited[v] = true;
	for (ull i = 0; i < g[v].size(); i++) {
		ull to = g[v][i];
		if (!visited[to]) {
			if (g[to].size() > g[v].size()) cnt++;
			dfs(to);
		}
	}
}

int main() {
	cin >> m >> n;
	g.resize(m);
	visited.resize(m);
	for (ull i = 0; i < n; i++) {
		ull u, v;
		cin >> u >> v;
		u--; v--;
		g[u].push_back(v);
	}
	int res = 0;
	for (ull i = 0; i < m; i++) {
		if (!visited[i]) {
			dfs(i);
			res++;
		}
	}
	cout << cnt + res;

}