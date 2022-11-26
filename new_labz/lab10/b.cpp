// Path
#include <bits/stdc++.h>
using namespace std;

int main() {
	int n, x, y;
	cin >> n;
	vector<bool> visited(n);
	int adj_matrix[n][n];
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> adj_matrix[i][j];
		}
	}
	cin >> x >> y;
	x--; y--;

	if (x == y) {
		cout << 0;
		return 0;
	}

    int res = 0;
	queue<int> q;
	q.push(x);
	visited[x] = true;
	while (!q.empty()) {
		int u = q.front();
		res++;
		for (int i = 0; i < n; i++) {
			if (!visited[i] && adj_matrix[u][i]) {
				if (i == y) {
					cout << res;
					return 0;
				}
				visited[i] = true;
				q.push(i);
			}
		}
		q.pop();
	}
	cout << -1;
}