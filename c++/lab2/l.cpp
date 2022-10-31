#include <bits/stdc++.h>

using namespace std;

int main(){
    int n;
    cin >> n;
    for(int i = 0; i < n; i++){
        if(pow(2, i) <= n) cout << pow(2, i) << " ";
    }
}