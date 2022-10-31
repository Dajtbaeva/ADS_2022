#include <bits/stdc++.h>

using namespace std;

int main(){
    int n;
    cin >> n;
    int m = n * 2 - 1;
    char a[n][m];
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            a[i][j] = '.';
        }
    }
    for(int i = 0; i < n; i++){
        for(int j = n - i - 1; j <= n + i - 1; j++){
            a[i][j] = '*';
        }
    }
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cout << a[i][j];
        }
        cout << "\n";
    }
}