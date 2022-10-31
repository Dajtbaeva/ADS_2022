#include <bits/stdc++.h>

using namespace std;

int main(){
    int n, m;
    cin >> n >> m;
    int a[n][m];
    int sr, sc;

    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cin >> a[i][j];
        }
    }
    for(int i = 0; i < n; i++){
        sr = 0;
        for(int j = 0; j < m; j++){
            sr += a[i][j];
        } cout << "The sum of row number " << i + 1 << " is " << sr << "\n";
    }
    for(int j = 0; j < m; j++){
        sc = 0;
        for(int i = 0; i < n; i++){
            sc += a[i][j];
        } cout << "The sum of column number " << j + 1 << " is " << sc << "\n";
    }
}