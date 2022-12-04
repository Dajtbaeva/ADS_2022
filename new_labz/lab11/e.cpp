#include <bits/stdc++.h>
using namespace std;

vector<vector<int> > g;
vector<int> p;

int dsu_get_parent(int v) {
	if (v == p[v]) return v;
	return p[v] = dsu_get_parent(p[v]);
}

bool dsu_unite(int a, int b) {
	a = dsu_get_parent(a);
	b = dsu_get_parent(b);
	if(a != b){
		p[a] = b;
		return true;
	} 
	return false;
}

int main() {
	int n, m, cnt = 0;
	cin >> n >> m;
	p.resize(n);
	g.resize(n);
	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;
		a--; b--;
		g[a].push_back(b);
		g[b].push_back(a);
	}

	for (int i = 0; i < n; ++i) p[i] = i;
	
	vector<int> ans;
	for(int i = n - 1; i >= 0; i--){
		ans.push_back(cnt);
		cnt++;
		for(int j = 0; j < g[i].size(); j++){
			int u = g[i][j];
			if(i < u){
				if(dsu_unite(i, u)) cnt--;
			} 
		}
	}
	reverse(ans.begin(), ans.end());
	for(int i = 0; i < ans.size(); i++){
		cout << ans[i] << "\n";
	}
}