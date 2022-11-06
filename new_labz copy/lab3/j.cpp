#include <bits/stdc++.h>

using namespace std;

bool checker(int a[], int n, int x, int h){
    int t = 0;
    for(int i = 0; i < n; i++){
        t += (a[i] + x - 1) / x; 
    }
    return t <= h;
}

int main(){
    int n, h;
    cin >> n >> h;
    int a[n];
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
    int l = 0, r = 1e9;
    while(r - l > 1){
        int mid = l + (r - l) / 2;
        if(checker(a, n, mid, h)) r = mid;
        else l = mid;
    }
    cout << r;
}