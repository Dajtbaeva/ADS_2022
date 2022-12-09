#include <bits/stdc++.h>

using namespace std;

const int MAXI = 505;
const int N = -1e7;

int main(){
    // freopen("input.txt", "r", stdin);
	// freopen("output.txt", "w", stdout);
    int n, m, x, y, c, mx;
    int q[MAXI], d[MAXI][MAXI], color[MAXI];
    vector<pair<int, int> > g[MAXI];
    vector<int> p[MAXI];
    bool visited[MAXI], w[MAXI];
    cin >> n;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            cin >> d[i][j];
        }
    }

    for(int k = 1; k <= n; k++){
        cin >> x;
        visited[x] = 1;
        mx = -1;
        for(int i = 1; i <= n;i++){
            for(int j = 1; j <= n; j++) d[i][j] = min(d[i][j], d[i][x] + d[x][j]);
        }
        for(int i = 1; i <= n;i++){
            for(int j = 1; j <= n; j++){
                if(visited[i] && visited[j]) mx = max(mx, d[i][j]);
            }
        }
        cout << mx << "\n";
    }

}
