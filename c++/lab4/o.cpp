#include <bits/stdc++.h>

using namespace std;

int main(){
    int n, k, m;
    cin >> n;
    int a[n][n];
    int maxi = -2147483647 - 1;

    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cin >> a[i][j];
        }
    }
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if(j == i && maxi < a[i][j]){
                maxi = a[i][j];
                k = i;
                m = j;
            }
        }
    }
    cout << "Maximum element is: " << maxi << " with coordinates: " << k + 1 << ";" << m + 1;
}