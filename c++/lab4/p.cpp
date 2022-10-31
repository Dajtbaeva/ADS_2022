#include <bits/stdc++.h>

using namespace std;

int main(){
    int n, k, m;
    cin >> n;
    int a[n][n];
    int sumi = 0;

    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cin >> a[i][j];
            if(i + j == n - 1) sumi += a[i][j];
        }
    }
    cout << sumi;
}