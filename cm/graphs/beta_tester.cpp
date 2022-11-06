#include <bits/stdc++.h>
using namespace std;
vector<vector<int> > g;
vector<int> p;
vector<int> colors; // 0 unvis, 1 red, 2 blue
vector<int> top_sort;
vector<bool> visited;
int cycle_start, cycle_end;

bool dfs(int v) {
	colors[v] = 1;
	for (int i = 0; i < g[v].size(); i++) {
		int u = g[v][i];
		if (colors[u] == 1) {
			return true;
		}
		if (colors[u] == 0) {
			p[u] = v;
			if (dfs(u)) return true;
		}
	}
	colors[v] = 2;
	return false;
}

void dfs_sort(int v){
    visited[v] = true;
    for(int i = 0; i < g[v].size(); i++){
        int u = g[v][i];
        if(!visited[u]) dfs_sort(u);
    }
    top_sort.push_back(v);
}

int main() {
	int m, n;
	cin >> m >> n;
	colors.resize(m);
    visited.resize(m);
	g.resize(m);
	p.resize(m);
	for (int i = 0; i < n; i++) {
		int u, v;
		cin >> u >> v;
		u--;
		v--;
		g[u].push_back(v);
	}
	cycle_start = -1;
	for (int i = 0; i < m; i++) {
		if (dfs(i)) break;
	}
	if (cycle_start == -1) {
		reverse(top_sort.begin(), top_sort.end());
        cout << "Possible\n";
        for(auto i : top_sort) cout << i + 1 << " ";
	} else {
        cout << "Impossible\n";
	}

	return 0;
}
