#include <bits/stdc++.h>

using namespace std;

int main (){
    int n, m;
    cin >> n >> m;
    int a[n][m];
    int b[n];
    int mini = 2147483647;
    int sumi;

    for(int i = 0; i < n; i++){
        sumi = 0;
        for(int j = 0; j < m; j++){
            cin >> a[i][j];
            sumi += a[i][j];
        }
        b[i] = sumi;
        if(b[i] < mini) mini = b[i];
    }
    for(int i = 0; i < n; i++){
        if(b[i] == mini){
            cout << i + 1;
            return 0;
        }
    }
}