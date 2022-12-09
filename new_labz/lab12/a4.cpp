#include <bits/stdc++.h>

using namespace std;
 
int n, d[1000][1000], x[1000];
bool used[1000];
vector <int> res;

int main(){
    cin >> n;
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n; j++) {
            cin >> d[i][j];
        }
    }

    for(int i = 1; i <= n; i++) {
        cin >> x[i];
    }

    for(int k = 1; k <= n; k++) {
        used[x[k]] = 1;
        int ans = 0;
        for(int i = 1; i <= n; i++){ 
            for(int j = 1; j <= n; j++){
                d[i][j] = min(d[i][j], d[i][x[k]] + d[x[k]][j]);

                if(used[i] && used[j]){
                    ans = max(d[i][j], ans);
                }
            }
        }
        res.push_back(ans);
    }
    for(auto i : res){
        cout << i << endl;
    }
}
