#include <bits/stdc++.h>

using namespace std;

int main(){
    int n;
    cin >> n;
    for(int i = 1; i <= n; i++){
        if(pow(i, 2) <= n) cout << pow(i, 2) << "\n";
    }
}