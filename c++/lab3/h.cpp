#include <bits/stdc++.h>

using namespace std;

int main(){
    int n, l, r;
    cin >> n >> l >> r;
    int a[n];
    int sumi = 0;
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
    for(int i = l - 1; i < r; i++){
        sumi += a[i];
    }
    cout << sumi;
}