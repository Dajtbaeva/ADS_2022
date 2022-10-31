#include <bits/stdc++.h>

using namespace std;

int main(){
    int n;
    int res = 0;
    cin >> n;
    for(int i = 1; i <= n; i++){
        res += i;
    }
    cout << res;
}