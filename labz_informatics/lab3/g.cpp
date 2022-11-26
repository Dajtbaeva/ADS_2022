// Задача №4. Двоичный поиск
// https://informatics.msk.ru/mod/statements/view.php?id=54422&chapterid=4#1

#include <bits/stdc++.h>

using namespace std;

int bs(int a[], int l, int r, int x){
    while(l <= r){
        int mid  = (l + r) / 2;
        if(a[mid] == x) return mid;
        if(a[mid] < x) l = mid + 1;
        else r = mid - 1;
    }
    return -1;
}

int main(){
    int n, m, x;
    cin >> n;
    int a[n];
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
    cin >> m;
    for(int i = 1; i <= n; i++){
        if(bs(a, 0, n - 1, m) != -1) cout << "Yes";
        else cout << "No";
    }
}