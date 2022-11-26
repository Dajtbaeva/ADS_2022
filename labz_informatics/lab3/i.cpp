// Задача №111728. Левый и правый двоичный поиск
// https://informatics.msk.ru/mod/statements/view.php?id=54422&chapterid=111728#1

#include <bits/stdc++.h>

using namespace std;

void bs(int a[], int l, int r, int x){
    while(l < r){
        int mid = (l + r) / 2;
        if(a[mid] < x) l = mid + 1;
        else r = mid;
    }
    if(a[r] == x){
        cout << ++r << " ";
        while(a[r] == x) r++;
        cout << r << "\n";
    }
    else cout << 0 << "\n";
}

int main(){
    int n, k;
    cin >> n >> k;
    int b[n];
    for(int i = 0; i < n; i++){
        cin >> b[i];
    }
    for(int i = 1; i <= k; i++){
        int y;
        cin >> y;
        bs(b, 0, n - 1, y);
    }
        
}