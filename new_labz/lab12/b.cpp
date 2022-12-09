#include <bits/stdc++.h>

using namespace std;
#define ull unsigned long long
vector<ull> d;
vector<bool> used;
vector<vector<pair<ull, ull> > > g;
const int INF = 1e9;

int main(){
	ull n, m; cin >> n >> m;
    used.resize(n);
	g.resize(n);
    d.assign(n, INF);
	for (ull i = 0; i < m; i++) {
		ull u, v, w;
		cin >> u >> v >> w; u--; v--;
		g[u].push_back({v, w});
		g[v].push_back({u, w});
	}
	ull a, b, s, f; cin >> s >> a >> b >> f;
	s--; a--; b--; f--; d[s] = 0;

    vector <ull> path1, path2;
	priority_queue <pair<int, int> > q;
	q.push({0, s});
	while(!q.empty()) {
		int v = q.top().second, cur = -q.top().first;
		q.pop();
		if (cur > d[v])  continue;
		for (size_t j = 0; j < g[v].size(); j++) {
			int to = g[v][j].first, len = g[v][j].second;
			if (d[v] + len < d[to]) {
				d[to] = d[v] + len;
				q.push({-d[to], to});
			}
		}
	}
	path1.push_back(d[a]);
    used.assign(n, false);
    d.assign(n, INF);
    while(!q.empty()) q.pop();
    d[a] = 0;
    q.push({0, a});
	while (!q.empty()) {
		int v = q.top().second, cur = -q.top().first; q.pop();
		if (cur > d[v])  continue;
		for (size_t j = 0; j < g[v].size(); j++) {
			int to = g[v][j].first, len = g[v][j].second;
			if (d[v] + len < d[to]) {
				d[to] = d[v] + len;
				q.push({-d[to], to});
			}
		}
	}
	path1.push_back(d[b]);
    used.assign(n, false);
    d.assign(n, INF);
    while(!q.empty()) q.pop();
    d[b] = 0;
    q.push({0, b});
	while (!q.empty()) {
		int v = q.top().second, cur = -q.top().first; q.pop();
		if (cur > d[v])  continue;
		for (size_t j = 0; j < g[v].size(); j++) {
			int to = g[v][j].first, len = g[v][j].second;
			if (d[v] + len < d[to]) {
				d[to] = d[v] + len;
				q.push({-d[to], to});
			}
		}
	}
	path1.push_back(d[f]);
    used.assign(n, false);
    d.assign(n, INF);
    while(!q.empty()) q.pop();
    d[s] = 0;
    q.push({0, s});
	while (!q.empty()) {
		int v = q.top().second, cur = -q.top().first; q.pop();
		if (cur > d[v])  continue;
		for (size_t j = 0; j < g[v].size(); j++) {
			int to = g[v][j].first, len = g[v][j].second;
			if (d[v] + len < d[to]) {
				d[to] = d[v] + len;
				q.push({-d[to], to});
			}
		}
	}
	path2.push_back(d[b]);
    used.assign(n, false);
    d.assign(n, INF);
    while(!q.empty()) q.pop();
    d[b] = 0;
    q.push({0, b});
	while (!q.empty()) {
		int v = q.top().second, cur = -q.top().first; q.pop();
		if (cur > d[v])  continue;
		for (size_t j = 0; j < g[v].size(); j++) {
			int to = g[v][j].first, len = g[v][j].second;
			if (d[v] + len < d[to]) {
				d[to] = d[v] + len;
				q.push({-d[to], to});
			}
		}
	}
	path2.push_back(d[a]);
    used.assign(n, false);
    d.assign(n, INF);
    while(!q.empty()) q.pop();
    d[a] = 0;
    q.push({0, a});
	while (!q.empty()) {
		int v = q.top().second, cur = -q.top().first; q.pop();
		if (cur > d[v])  continue;
		for (size_t j = 0; j < g[v].size(); j++) {
			int to = g[v][j].first, len = g[v][j].second;
			if (d[v] + len < d[to]) {
				d[to] = d[v] + len;
				q.push({-d[to], to});
			}
		}
	}
	path2.push_back(d[f]);
    used.assign(n, false);
    d.assign(n, INF);
    while(!q.empty()) q.pop();
	ull s1 = 0, s2 = 0;
	for(int i = 0; i < path1.size(); i++){
		if(path1[i] != INF) s1 += path1[i];
		else{
			s1 = -1;
			break;
		}
	}
	for(int i = 0; i < path2.size(); i++){
		if(path2[i] != INF) s2 += path2[i];
		else{
			s2 = -1;
			break;
		}
	}
	(s1 == -1 && s2 == -1) ? cout << -1 : cout << min(s1, s2);
}