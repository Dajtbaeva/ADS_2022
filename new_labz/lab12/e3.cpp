#include <bits/stdc++.h>
 
#define ios ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define file(s) if (fopen(s".in", "r")) freopen(s".in", "r", stdin), freopen(s".out", "w", stdout)
#define all(a) a.begin() , a.end()
#define F first
#define S second
 
using namespace std;
using ll = long long;
 
const int N = 100+5 , inf = 2e9 + 7;
const ll INF = 1e18 ,   mod = 1e9+7 , P = 6547;

int a[N][N];

void solve() {
	int n;
	cin >> n;
	for(int i = 1; i <= n; i ++) {
		for(int j = 1; j <= n; j ++) {
			cin >> a[i][j];
		}
	}
	
	for(int v = 1; v <= n; v ++) {
		vector<int> d(n+1, inf);
		d[v] = 0;
		vector<int> p(n+1, -1);
		int V;
		for(int i = 1; i <= n; i ++) {
			V = -1;
			for(int i = 1; i <= n; i ++) {
				for(int j = 1; j <= n; j ++) {
					if(a[i][j] == 10000) continue;
					if (d[i] < inf) {
						if (d[j] > d[i] + a[i][j]) {
							d[j] = max (-inf, d[i] + a[i][j]);
							p[j] = i;
							V = j;
						}
					}
				}
			}
		}
	 
	 	if(V == -1) {
	 		continue;
	 	}
		else {
			int st = V;
			for(int i = 1; i <= n; i ++)
				st = p[st];
	 
	 
	 		vector<int> vec;
	 		int cur = st;
	 		while(1) {
	 			vec.push_back(cur);
	 			if(cur == st && vec.size() > 1) break;
	 			cur = p[cur];
	 		}
	 		reverse(all(vec));
	 
			cout << "YES\n";
			cout << vec.size() << '\n';
			for(auto to: vec) {
				cout << to << ' ';
			}
			return;
		}
	}
	cout << "NO";
}
/*
*/
main() {
    ios;
    int tt = 1 , tc = 0;
    // cin >> tt;
    while(tt --) {
        solve();
    }
    return 0;
}