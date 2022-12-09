#include <bits/stdc++.h>
 
#define ios ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define file(s) if (fopen(s".in", "r")) freopen(s".in", "r", stdin), freopen(s".out", "w", stdout)
#define all(a) a.begin() , a.end()
#define F first
#define S second
 
using namespace std;
using ll = long long;
 
const int N = 400+5 , inf = 2e9 + 7;
const ll INF = 1e18 ,   mod = 1e9+7 , P = 6547;

int a[N][N];

void solve(int tc) {
	int n , m;
	cin >> n >> m;
	for(int i = 1; i <= m; i ++) {
		int u,v;
		cin >> u >> v;
		a[u][v] = 1;
		a[v][u] = 1;
	}
	int ok = 1;
	if(a[1][n] == 1) ok = 0;
	queue<int> q;
	q.push(1);
	vector<int> d(n+1, inf);
	d[1] = 0;
	
	while(q.size()) {
		int cur = q.front();
		q.pop();
		for(int i = 1; i <= n; i ++) {
			if(i == cur) continue;
			if(a[cur][i] == ok && d[cur]+1 < d[i]) {
				d[i] = d[cur]+1;
				q.push(i);
			}
		}
	}
	if(d[n] == inf) d[n] = -1;
	cout << d[n];
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