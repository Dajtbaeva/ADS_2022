// Задача №1422. Шестеренки
// https://informatics.msk.ru/mod/statements/view.php?chapterid=1422#1

#include <bits/stdc++.h>

using namespace std;

int gcd(int a, int b){
    if(b == 0) return a;
    else return gcd(b, a % b);
}

int lcm(long long a, long long b){
    return (a * b) / gcd(a, b);
}

int main(){
    long long n, m;
    cin >> n >> m;
    cout << lcm(n, m);
}


