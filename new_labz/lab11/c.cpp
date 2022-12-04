#include <bits/stdc++.h>
using namespace std;

vector<pair<int, pair<int, int> > > g;
vector<int> p;


int mstGet(int n) {
	if (n == p[n]) return n; 
    else return p[n] = mstGet(p[n]);
}

void mst_unite(int a, int b) {
	a = mstGet(a);
	b = mstGet(b);
	if (a != b) p[a] = b;
}

int main() {
	int n, m, x, y, total = 0;
	cin >> n >> m >> x >> y;
	p.resize(n);
	int forBoth = min(x, y);
	for (int i = 0; i < m; i++) {
		string type;
		int u, v, c;
		cin >> type >> u >> v >> c;
		u--; v--;
		if (type == "big") c *= x;
        else if (type == "small") c *= y;
        else c *= forBoth;
        g.push_back(make_pair(c, make_pair(u, v)));
	}

	sort(g.begin(), g.end());

	for (int i = 0; i < n; ++i) p[i] = i;

	for (int i = 0; i < g.size(); i++) {
		int u = g[i].second.first;
		int v = g[i].second.second;
		int c = g[i].first;
		if (mstGet(u) != mstGet(v)) {
			total += c;
			mst_unite(u, v);
		}
	}
	cout << total;
}