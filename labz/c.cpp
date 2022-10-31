#include <bits/stdc++.h>

using namespace std;

int main(){
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int n;
    cin >> n;
    bool ok = false;
    ((n % 4 == 0 && n % 100 != 0) || (n % 400 == 0)) ? ok = true : ok = false;
    cout << ok;
}