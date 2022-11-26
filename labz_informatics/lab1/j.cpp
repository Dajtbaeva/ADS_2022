// Задача №147. Алгоритм Евклида
// https://informatics.msk.ru/mod/statements/view.php?chapterid=147#1

#include <bits/stdc++.h>

using namespace std;

int gcd(int a, int b){
    if(b == 0) return a;
    else return gcd(b, a % b);
}

int main(){
    int n, m;
    cin >> n >> m;
    cout << gcd(n, m);
}