#include <bits/stdc++.h>

using namespace std;

int main (){
    int n;
    cin >> n;
    for(int i = 2; i <= n; i++){
        bool p = false;
        for(int j = 2; j < i; j++){
            if(i % j == 0) p = true;
        }
        if(p == false) cout << i << " is prime\n";
    }
}