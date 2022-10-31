// Задача №1427. Матрица
// https://informatics.msk.ru/mod/statements/view.php?id=54422&chapterid=1427#1
// Седловой точкой этой матрицы назовем элемент, который одновременно является минимумом в своей строке и максимумом в своем столбце.


#include <bits/stdc++.h>

using namespace std;

int main(){
    int n, m, cnt = 0;
    int k = 0;
    cin >> n >> m;
    int a[n][m];
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cin >> a[i][j];
        }
    }
    int check = a[0][0];
    bool ok = true;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(a[i][j] != check) ok = false;
        }
    }
    if(ok){
        cout << (n * m);
        return 0;
    }


    for(int i = 0; i < n; i++){
        int mini = a[i][0];
        int pos = 0;
        for(int j = 0; j < m; j++){
            if(a[i][j] < mini){
                mini = a[i][j];
                pos = j;
            } 
        }
        int maxi = a[0][pos];
        for(int l = 0; l < n; l++){
            if(a[l][pos] > maxi) maxi = a[l][pos];
        }
        if(mini == maxi) cnt++;
    }
    cout << cnt;
}