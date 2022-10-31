#include <bits/stdc++.h>

using namespace std;

int main (){
    int n;
    cin >> n;
    int a[n][n];

    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++)
        cin >> a[i][j];
    }
    int x = a[0][0];
    int k = 0;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if(x == a[i][j]) k += 1;
        }
    }
    if(k == n * n) cout << 0;
    else{
        int maxi1 = a[0][0];
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                if(maxi1 <= a[i][j]) maxi1 = a[i][j];
            }
        }
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                if(a[i][j] == maxi1) a[i][j] = -1000000000;
            }
        }
        int maxi2 = a[0][0];
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                if(maxi2 <= a[i][j]) maxi2 = a[i][j];
            }
        }
        cout << maxi2;
    }
}