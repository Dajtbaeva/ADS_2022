#include <bits/stdc++.h>

using namespace std;

int getcnt(int n){
    int cnt = 0;
    for(int i = 1; i <= n; i++){
        if(n % i == 0) cnt++;
    }
    return cnt == 3 || cnt == 4;
}


int main() {
    int n;
    cin >> n;
    int cnt = 0;
    for(int i = 1; i <= n; i++){
        if(getcnt(i)) cnt++;
    }
    cout << cnt << endl;
    return 0;
}