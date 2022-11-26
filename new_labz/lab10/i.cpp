#include <bits/stdc++.h>
using namespace std;

vector<vector<int> > g;
vector<bool> vis;
vector<int> res, colors;

bool isThereCycle(int v) {
	colors[v] = 1;
	for (int i = 0; i < g[v].size(); i++) {
		int u = g[v][i];
		if (colors[u] == 1) return true;
		if (colors[u] == 0) {
			if (isThereCycle(u)) return true;
		}
	}
	colors[v] = 2;
	return false;
}

void topsorting(int v) {
	vis[v] = true;
	for (int i = 0; i < g[v].size(); i++) {
		int u = g[v][i];
		if (!vis[u]) {
			topsorting(u);
		}
	}
	res.push_back(v);
}

int main() {
	int m, n;
	cin >> m >> n;
	colors.resize(m);
	g.resize(m);
	vis.resize(m);
	for (int i = 0; i < n; i++) {
		int u, v;
		cin >> u >> v;
		u--; v--;
		g[u].push_back(v);
	}
	bool hasCycle = false;
	for (int i = 0; i < m; i++) {
		if (isThereCycle(i)) {
			hasCycle = true;
			break;
		}
	}
	if (!hasCycle) {
		cout << "Possible\n";
		for (int i = 0; i < m; i++) {
			if (!vis[i]) topsorting(i);
		}
		reverse(res.begin(), res.end());
		for (auto i : res) {
			cout << i + 1 << " ";
		}
	} else cout << "Impossible";
}