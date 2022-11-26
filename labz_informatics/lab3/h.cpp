// Задача №3. Сложность двоичного поиска
// https://informatics.msk.ru/mod/statements/view.php?id=54422&chapterid=3#1

#include <bits/stdc++.h>

using namespace std;

int main(){
    int n, k = 0;
    cin >> n;
    int m = 1;
    while(m < n){
        m *= 2;
        k++;
    }
    cout << k;
}