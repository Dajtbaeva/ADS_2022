#include <bits/stdc++.h>
 
#define ios ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define file(s) if (fopen(s".in", "r")) freopen(s".in", "r", stdin), freopen(s".out", "w", stdout)
#define all(a) a.begin() , a.end()
#define F first
#define S second
 
using namespace std;
using ll = long long;
 
const int N = 2e5+5 , inf = 2e9 + 7;
const ll INF = 1e18 ,   mod = 1e9+7 , P = 6547;

int x[N], y[N];
int p[N];

int get(int v) {
	if(v == p[v]) return v;
	return p[v] = get(p[v]);
}

bool merge(int a, int b) {
	a = get(a);
	b = get(b);
	if(a == b) return 0;
	if(rand()%2) swap(a, b);
	p[b] = a;
	return 1;
}

void solve(int tc) {
	int n;
	cin >> n;
	for(int i = 1; i <= n; i ++) {
		cin >> x[i] >> y[i];
	}
	int l = 0, r = inf, ans;
	while(l <= r) {
		int md = l+r >> 1;
		for(int i = 1; i <= n; i ++) p[i] = i;
		for(int i = 1; i <= n; i ++) {
			for(int j = 1; j <= n; j ++) {
				if(abs(x[i]-x[j])+abs(y[i]-y[j]) <= md) merge(i , j);
			}
		}
		if(get(1) == get(n)) {
			ans = md;
			r = md-1;
		}
		else {
			l = md+1;
		}
	}
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