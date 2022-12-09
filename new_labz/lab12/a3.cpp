#include <bits/stdc++.h>
 
#define ios ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define file(s) if (fopen(s".in", "r")) freopen(s".in", "r", stdin), freopen(s".out", "w", stdout)
#define all(a) a.begin() , a.end()
#define F first
#define S second
 
using namespace std; 
using ll = long long;
 #define int ll
const int N = 500+5 , inf = 2e9 + 7;
const ll INF = 1e18 ,   mod = 1e9+7 , P = 6547;

int a[N][N];
int mn[N][N];
int x[N];
int u[N];
int n;	

void solve(int tc) {
	cin >> n;
	for(int i = 1; i <= n; i ++) {
		for(int j = 1; j <= n; j ++) {
			cin >> a[i][j];
			mn[i][j] = inf;
		}
	}
	for(int i = 1; i <= n; i ++) {
		cin >> x[i];
		int ans = 0;
		for(int j = 1; j <= i; j ++) {
			mn[x[j]][x[i]] = a[x[j]][x[i]];
			mn[x[i]][x[j]] = a[x[i]][x[j]];
		}
		for(int k = 1; k <= i; k ++) {
			for(int t = 1; t <= i; t ++) {
				mn[x[t]][x[i]] = min(mn[x[t]][x[i]] , mn[x[t]][x[k]] + mn[x[k]][x[i]]);
			}
		}
		for(int k = 1; k <= i; k ++) {
			for(int t = 1; t <= i; t ++) {
				mn[x[i]][x[t]] = min(mn[x[i]][x[t]] , mn[x[i]][x[k]] + mn[x[k]][x[t]]);
			}
		}
		for(int k = 1; k <= i; k ++) {
			for(int t = 1; t <= i; t ++) {
				mn[x[k]][x[t]] = min(mn[x[k]][x[t]] , mn[x[k]][x[i]] + mn[x[i]][x[t]]);
				if(mn[x[k]][x[t]] < inf) {
					ans = max(ans, mn[x[k]][x[t]]);
				}
			}
		}
		cout << ans << '\n';
	}
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