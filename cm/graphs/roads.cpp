// https://acmp.ru/asp/do/index.asp?main=task&id_course=2&id_section=21&id_topic=48&id_problem=625
#include <bits/stdc++.h>
using namespace std;

vector<vector<int> > g;
vector<bool> visited;

void dfs(int v) {
	visited[v] = true;
	cout << v << " ";
	for (int i = 0; i < g[v].size(); i++) {
		int u = g[v][i];
		if (!visited[u]) {
			dfs(u);
		}
	}
}

int main() {
	int m, n; // vertices and edges
	cin >> m;
	int adj_matrix[m][m];
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < m; j++) {
			cin >> adj_matrix[i][j];
		}
	}
	int cnt = 0;
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < m; j++) {
			if(adj_matrix[i][j]) cnt++;
		}
	}
	cout << cnt / 2;
}