#include <bits/stdc++.h>
 
#define ios ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define file(s) if (fopen(s".in", "r")) freopen(s".in", "r", stdin), freopen(s".out", "w", stdout)
#define all(a) a.begin() , a.end()
#define F first
#define S second
 
using namespace std;
using ll = long long;
 #define int ll
const int N = 2e5+5 , inf = 2e9 + 7;
const ll INF = 1e18 ,   mod = 1e9+7 , P = 6547;

vector<pair<int,int>> g[N];
int n , m;

vector<int> dij(int v) {
	vector<int> d(n+1, inf);
	d[v] = 0;
	set<pair<int,int>> st;
	st.insert({0, v});
	while(st.size()) {
		pair<int,int> cur = *st.begin();
		st.erase(cur);
		for(auto to: g[cur.S]) {
			if(d[cur.S]+to.S < d[to.F]) {
				st.erase({d[to.F], to.F});
				d[to.F] = d[cur.S]+to.S;
				st.insert({d[to.F], to.F});
			}
		}
	}
	return d;
}

void solve(int tc) {
	cin >> n >> m;
	for(int i = 1; i <= m; i ++) {
		int a, b, c;
		cin >> a >> b >> c;
		g[a].push_back({b,c});
		g[b].push_back({a,c});
	}
	int s,a,b,f;
	cin >> s>>a>>b>>f;
	vector<int> d1 = dij(s);
	vector<int> d2 = dij(a);
	vector<int> d3 = dij(b);
	vector<int> d4 = dij(f);
	int ans = min(d1[a] + d2[b] + d3[f] , d1[b]+d3[a]+d2[f]);
	if(ans > inf) ans = -1;
	cout << ans;
}
/*
*/
main() {
    ios;
    int tt = 1 , tc = 0;
    // cin >> tt;
    while(tt --) {
        solve(++tc);
    }
    return 0;
}