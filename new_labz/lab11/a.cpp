#include <bits/stdc++.h>
using namespace std;
#define ull unsigned long long

vector<pair<ull, pair<ull, ull> > > g;
vector<ull> p;

ull dsu_get(ull v) {
	if (v == p[v]) return v; 
    else return p[v] = dsu_get(p[v]);
}

void dsu_unite(ull a, ull b) {
	a = dsu_get(a);
	b = dsu_get(b);
	if (a != b) p[a] = b;
}

int main() {
	ull n, q, total = 0;
	cin >> n >> q;
	p.resize(n);
	for(ull i = 0; i < q; i++) {
		ull l, r, c;
		cin >> l >> r >> c;
		l--; r--;
		g.push_back(make_pair(c, make_pair(l, r)));
	}
	
	sort(g.begin(), g.end());

	for (ull i = 0; i < n; ++i) p[i] = i;
	
	for (ull i = 0; i < g.size(); ++i) {
		ull u = g[i].second.first;
		ull v = g[i].second.second;
		ull cost = g[i].first;
		for(int j = u + 1; j <= v; j++){
			if (dsu_get(u) != dsu_get(j)) {
				total += cost;
				dsu_unite(u, j);
			}else j = p[u];
		}
	}
	cout << total;
}