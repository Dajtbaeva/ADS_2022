#include <bits/stdc++.h>

using namespace std;

int main(){
    // freopen("input.txt", "r", stdin);
    int n, x;
    cin >> n;
    vector<int> v;
    for(int i = 0; i < n; i++){
        cin >> x;
        if(!v.empty()){
            bool ok = false;
            for(int i = v.size() - 1; i >= 0; i--){
                if(v[i] <= x){
                    cout << v[i] << " ";
                    ok = true;
                    break;
                } 
            }
            if(!ok) cout << -1 << " ";
        }else cout << -1 << " ";
        v.push_back(x);
    }
}
// 5
// 2 1 5 8 3 -> -1 -1 1 5 1
// 2 