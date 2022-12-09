#include <bits/stdc++.h>

using namespace std;

int main(){
    int n;
    int m = 0;
    bool ok = 0;
    long long c; 
    cin >> n;
    vector<vector<pair<int, long long> > > g(n + 1);
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            m++;
            cin >> c;
            if(c == 100000) continue;
            g[i + 1].push_back({j + 1, c});
        }
    }

    vector<long long> d(n + 1, 1e14);
    vector<long long> p(n + 1, -1);

    for(int i = 1; i < n; i++){
        for(int j = 1; j <= n; j++){
            for(auto k : g[j]){
                long long v = k.first, c = k.second;
                if(d[v] > d[j] + c){
                    d[v] = d[j] + c;
                    p[v] = j;
                }
            }
        }
    }
    for(int i = 1; i <= n; i++){
        for(auto k : g[i]){
            long long v = k.first, c = k.second;
            if(d[v] > d[i] + c){
                ok = 1;
                d[v] = d[i] + c;
                p[v] = i;
            }
            if(ok){
                cout << "YES\n";
                vector<int> res;
                vector<bool> used(n + 1, 0);
                while(!used[i]){
                    used[i] = 1;
                    i = p[i];
                }
                int u = i; res.push_back(u); u = p[u];
                while(u ^ i){
                    res.push_back(u);
                    u = p[u];
                }
                res.push_back(u);
                reverse(res.begin(), res.end());
                cout << res.size() << "\n";
                for(auto f : res) cout << f << " ";
                return 0;
            }
        }
    }
    if(!ok) cout << "NO\n";
}