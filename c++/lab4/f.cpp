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
    int maxi = a[0][0];

    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if(a[i][j] > maxi) maxi = a[i][j];
        }
    }
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if(a[i][j] == maxi){
                cout << i + 1 << " " << j + 1;
                return 0;
            }
        }
    }
}