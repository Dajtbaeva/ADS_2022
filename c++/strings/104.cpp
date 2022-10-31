#include <bits/stdc++.h>

using namespace std;

int main(){
    char c;
    cin >> c;
    if(int(c) >= 97 && int(c) <= 122) cout << char(int(c - 32)); // a
    else cout << char(int(c + 32)); // 65 -> 97
}