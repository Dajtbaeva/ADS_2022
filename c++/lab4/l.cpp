#include <bits/stdc++.h>

using namespace std;

int main(){
    int n, m;
    cin >> n >> m;
    int a[n][m];
    int mini, sumi = 0;
    int k;

    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cin >> a[i][j];
        }
    }
    cout << "coordinates of min elements:\n";
    for(int j = 0; j < m; j++){
        mini = 2147483647;
        for(int i = 0; i < n; i++){
            if(a[i][j] < mini){
                mini = a[i][j];
                k = i;
            } 
        } 
        sumi += mini;
        cout << k + 1 << ";" << j + 1 << "\n";
    } 
    cout << "Their sum:\n" << sumi;
}