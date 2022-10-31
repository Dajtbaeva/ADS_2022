#include <bits/stdc++.h>

using namespace std;

int main(){
    int n, m, k;
    cin >> n >> m >> k;
    vector<int> res;
    for(int i = 1; i <= n; i++){
        if(n % i == 0 && m % i == 0) res.push_back(i);
    }
    reverse(res.begin(), res.end());
    cout << res[k - 1];
}