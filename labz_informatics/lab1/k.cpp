// Задача №310. Проверка на простоту_0
// https://informatics.msk.ru/mod/statements/view.php?chapterid=310#1

#include <bits/stdc++.h>

using namespace std;

int main(){
    int n;
    cin >> n;
    if(n == 2 || n == 3){
        cout << "prime";
        return 0;
    }
    for(int i = 2; i * i <= n; i++){
        if(n % i == 0){
            cout << "composite";
            return 0;
        }
    }
    cout << "prime";
}