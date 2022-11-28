// Aho-Corazick
#include <bits/stdc++.h>
using namespace std;
int n, m;
int const x = 100001;
vector<vector<int> > g(100001);
vector<bool> visited(x);
vector<int> d(x), p(x);


void bfs(int v) {
	queue<int> q;
	q.push(v);
	visited[v] = true;
    p[v] = -1;
	while (!q.empty()) {
		int cur = q.front();
		q.pop();
		for (int i = 0; i < g[cur].size(); i++) {
			int to = g[cur][i];
			if (!visited[to]) {
				q.push(to);
				visited[to] = true;
                d[to] = d[cur] + 1;
			    p[to] = cur;
			}   
		}
	}
}

int main(){
    cin >> n >> m;
    for(int i = 1; i <= max(n,m) * 2; i++){
        g[i].push_back(i - 1);
        g[i].push_back(i * 2);
    }
    bfs(n);
    cout << d[m] << "\n";
    vector<int> path;
    for(int v = m;v != n;v = p[v]){
        path.push_back(v);
    }
    reverse(path.begin(), path.end());
    for(int i = 0; i < path.size(); i++)
        cout << path[i] << " ";
}