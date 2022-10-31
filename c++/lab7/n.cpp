#include <bits/stdc++.h>

using namespace std;

int n, k;
bool cheat(int b[], int i){
    if(i + 1 == n) return false;
    if(b[i + 1] - b[i] <= k) return true;
    return cheat(b, i + 1);
}

int main(){
    cin >> n >> k;
    int a[n];
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
    cheat(a, 0) ? cout << "cheater" : cout << "no";
}